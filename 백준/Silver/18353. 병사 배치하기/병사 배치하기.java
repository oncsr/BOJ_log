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
    static int[] A;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    public static void init() throws Exception {

        N = io.nextInt();
        A = new int[N];
        for(int i = 0; i < N; i++) A[i] = -io.nextInt();

    }

    static void solve() throws Exception {

        int[] dp = new int[N];
        dp[0] = 1;
        int max = 1;
        for(int i=1;i<N;i++) {
            dp[i] = 1;
            for(int j=0;j<i;j++) {
                if(A[j] < A[i]) dp[i] = Math.max(dp[i], dp[j]+1);
            }
            max = Math.max(max, dp[i]);
        }

        io.write((N-max) + "\n");

    }

}