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
    int x, y;
    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    int ccw(Point p1, Point p2) {
        long x1 = p1.x, y1 = p1.y;
        long x2 = p2.x, y2 = p2.y;
        long x3 = this.x, y3 = this.y;
        long res = x1*y2 + x2*y3 + x3*y1 - (x2*y1 + x3*y2 + x1*y3);
        if(res > 0) return 1;
        if(res < 0) return -1;
        return 0;
    }

    double dist(Point other) {
        double x1 = other.x, y1 = other.y;
        double x2 = this.x, y2 = this.y;
        double res = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        return Math.sqrt(res);
    }
}

public class Main {

    static IOController io;

    //

    static int N;
    static List<Point> list;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    public static void init() throws Exception {

        N = io.nextInt();
        list = new ArrayList<>();
        for(int i=0;i<N;i++) list.add(new Point(io.nextInt(),io.nextInt()));

    }

    static void solve() throws Exception {

        Collections.sort(list, (a,b) -> a.x==b.x ? a.y-b.y : a.x-b.x);
        List<Point> upper = new ArrayList<>();
        List<Point> lower = new ArrayList<>();
        for(Point p:list){
            while(upper.size()>1 && p.ccw(upper.get(upper.size()-2), upper.get(upper.size()-1)) >= 0) upper.remove(upper.size()-1);
            upper.add(p);
            while(lower.size()>1 && p.ccw(lower.get(lower.size()-2), lower.get(lower.size()-1)) <= 0) lower.remove(lower.size()-1);
            lower.add(p);
        }

        List<Point> convexHull = new ArrayList<>();
        for(int i=0;i<lower.size()-1;i++) convexHull.add(lower.get(i));
        for(int i=upper.size()-1;i>0;i--) convexHull.add(upper.get(i));

        if(convexHull.size() < 3) {
            io.write(convexHull.get(0).dist(convexHull.get(1)) + "\n");
            return;
        }

        double ans = Double.MAX_VALUE;
        double cur = convexHull.get(0).dist(convexHull.get(1));
        int j = 1;
        for(int i=0;i<convexHull.size();i++){
            Point p1 = convexHull.get((i+convexHull.size()-1)%convexHull.size());
            Point p2 = convexHull.get(i);
            Point t1 = convexHull.get(j);
            Point t2 = convexHull.get((j+1)%convexHull.size());
            Point p3 = new Point(t2.x-t1.x+p2.x,  t2.y-t1.y+p2.y);
            while(p3.ccw(p1, p2) >= 0) {
                j = (j+1)%convexHull.size();
                cur += convexHull.get(j).dist(convexHull.get((j+convexHull.size()-1)%convexHull.size()));
                t1 = convexHull.get(j);
                t2 = convexHull.get((j+1)%convexHull.size());
                p3 = new Point(t2.x-t1.x+p2.x,  t2.y-t1.y+p2.y);
            }
            ans = Math.min(ans, cur);
            cur -= convexHull.get(i).dist(convexHull.get((i+1)%convexHull.size()));
        }
        io.write(ans + "\n");

    }

}