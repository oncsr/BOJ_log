import java.util.*;
import java.io.*;

class IOController {
    BufferedReader br;
    BufferedWriter bw;
    StringTokenizer st;

    public IOController() {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        st = new StringTokenizer("");
    }

    String nextLine() throws Exception {
        String line = br.readLine();
        st = new StringTokenizer(line);
        return line;
    }

    String nextToken() throws Exception {
        while (!st.hasMoreTokens()) nextLine();
        return st.nextToken();
    }

    int nextInt() throws Exception {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws Exception {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws Exception {
        return Double.parseDouble(nextToken());
    }

    void close() throws Exception {
        bw.flush();
        bw.close();
    }

    void write(String content) throws Exception {
        bw.write(content);
    }

}

class Point {
    int x, y, z;
    Point(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
}

enum Direction {
    CLOCKWISE, COUNTER_CLOCKWISE, LINE;
}

public class Main {

    static IOController io;

    //

    static int N, M;
    static List<Point> arr;

    static Direction ccw(Point a, Point b, Point c) {
        long res = (long)a.x*b.y + (long)b.x*c.y + (long)c.x*a.y - ((long)b.x*a.y + (long)c.x*b.y + (long)a.x*c.y);
        if(res > 0) return Direction.CLOCKWISE;
        if(res < 0) return Direction.COUNTER_CLOCKWISE;
        return Direction.LINE;
    }

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    static void init() throws Exception {

        arr = new ArrayList<>();
        N = io.nextInt();
        for(int i=0;i<N;i++) arr.add(new Point(io.nextInt(), io.nextInt(), 0));
        M = io.nextInt();
        for(int i=0;i<M;i++) arr.add(new Point(io.nextInt(), io.nextInt(), 1));

    }

    static void solve() throws Exception {

        Collections.sort(arr, (a,b) -> a.x==b.x ? a.y-b.y : a.x-b.x);

        List<Point> lower = new ArrayList<>();
        List<Point> upper = new ArrayList<>();
        for(Point p:arr) {
            while(lower.size() > 1 && ccw(lower.get(lower.size()-2), lower.get(lower.size()-1), p) == Direction.CLOCKWISE) lower.remove(lower.size()-1);
            lower.add(p);
            while(upper.size() > 1 && ccw(upper.get(upper.size()-2), upper.get(upper.size()-1), p) == Direction.COUNTER_CLOCKWISE) upper.remove(upper.size()-1);
            upper.add(p);
        }

        List<Point> convexHull = new ArrayList<>();
        for(int i=0;i<lower.size()-1;i++) convexHull.add(lower.get(i));
        for(int i=upper.size()-1;i>0;i--) convexHull.add(upper.get(i));

        int ans = 0;
        for(int i=0;i<convexHull.size();i++) {
            int a = convexHull.get(i).z, b = convexHull.get((i+1)%convexHull.size()).z;
            if(a == 0 && b == 0) ans++;
        }
        io.write(ans + "\n");

    }

}