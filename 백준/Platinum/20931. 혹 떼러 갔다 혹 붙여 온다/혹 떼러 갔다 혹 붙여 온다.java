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

public class Main {

    static IOController io;

    //
    static final long INF = (long)7e18;

    static int Q;
    static int[][] par;
    static long[] dist;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    static void init() throws Exception {

        Q = io.nextInt();
        par = new int[150002][18];
        dist = new long[Q+1];
        dist[0] = INF;

    }

    static void solve() throws Exception {

        int last = 0, M = 1;
        while(Q-->0) {
            String op = io.nextToken();
            int x = io.nextInt();
            long l = io.nextLong();
            if(op.equals("ad-hoc")) {
                x = (x+last) % M;
                par[M][0] = x;
                for(int k=1;k<18;k++) par[M][k] = par[par[M][k-1]][k-1];
                dist[M] = dist[x] + l;
                M++;
            }
            else {
                if(dist[x] - l <= 0) {
                    io.write("0\n");
                    last = 0;
                    continue;
                }
                for(int k=17;k>=0;k--) if(dist[x] - dist[par[x][k]] <= l) {
                    l -= dist[x] - dist[par[x][k]];
                    x = par[x][k];
                }
                io.write(x + "\n");
                last = x;
            }
        }

    }

}