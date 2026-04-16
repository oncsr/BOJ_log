import java.io.*;
import java.util.*;

public class Main {

    static class IOManager {
        static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        static StringTokenizer st = new StringTokenizer("");

        private IOManager(){}

        static String nextLine() throws Exception {
            String line = br.readLine();
            st = new StringTokenizer(line);
            return line;
        }

        static String nextToken() throws Exception {
            while (!st.hasMoreTokens())
                nextLine();
            return st.nextToken();
        }

        static int nextInt() throws Exception {
            return Integer.parseInt(nextToken());
        }

        static long nextLong() throws Exception {
            return Long.parseLong(nextToken());
        }

        static double nextDouble() throws Exception {
            return Double.parseDouble(nextToken());
        }

        static void write(String content) throws Exception {
            bw.write(content);
        }

        public static void close() throws Exception {
            bw.flush();
            bw.close();
            br.close();
        }
    }

    //

    static class Point implements Comparable<Point> {
        int x, y;
        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Point o) {
            if (this.x == o.x) return this.y - o.y;
            return this.x - o.x;
        }
    }

    public static int ccw(Point a, Point b, Point c) {
        int res = (a.x * b.y + b.x * c.y + c.x * a.y) - (a.x * c.y + b.x * a.y + c.x * b.y);
        if (res > 0) return 1;
        if (res < 0) return -1;
        return 0;
    }

    static int N;
    static Point[] points;
    static long ans;

    public static void main(String[] args) throws Exception {
        input();
        solve();
        IOManager.write(ans + "");
        IOManager.close();
    }

    public static void input() throws Exception {
        N = IOManager.nextInt();
        points = new Point[N];

        for (int i = 0; i < N; i++) {
            int x = IOManager.nextInt(), y = IOManager.nextInt();
            points[i] = new Point(x, y);
        }
    }

    public static void solve() throws Exception {
        // Convex Hull
        Arrays.sort(points);

        List<Point> upper = new ArrayList<>();
        for (Point p : points) {
            while (upper.size() > 1 && ccw(upper.get(upper.size() - 2), upper.get(upper.size() - 1), p) >= 0) {
                upper.remove(upper.size() - 1);
            }
            upper.add(p);
        }

        List<Point> lower = new ArrayList<>();
        for (Point p : points) {
            while (lower.size() > 1 && ccw(lower.get(lower.size() - 2), lower.get(lower.size() - 1), p) <= 0) {
                lower.remove(lower.size() - 1);
            }
            lower.add(p);
        }

        List<Point> convexHull = new ArrayList<>();
        for (int i = 0; i < upper.size() - 1; i++) {
            convexHull.add(upper.get(i));
        }
        for (int i = lower.size() - 1; i > 0; i--) {
            convexHull.add(lower.get(i));
        }

        // Polygon Area
        double area = 0.0;

        for (int i = 0, sz = convexHull.size(); i < sz; i++) {
            area += convexHull.get(i).x * (convexHull.get((i + 1) % sz).y - convexHull.get((i + sz - 1) % sz).y);
        }

        ans = (long)(Math.abs(area) / 100.0);
    }

}