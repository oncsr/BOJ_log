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

    static final int INF = (int)1e9 + 7;
    static int N, M;
    static int[][] D;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    public static void init() throws Exception {

        N = io.nextInt();
        M = io.nextInt();
        D = new int[N+1][N+1];
        for(int i=1;i<=N;i++) {
            Arrays.fill(D[i], INF);
            D[i][i] = 0;
        }

        for(int i=1;i<=M;i++) {
            int u = io.nextInt(), v = io.nextInt(), b = io.nextInt();
            D[u][v] = 0;
            D[v][u] = b^1;
        }

    }

    static void solve() throws Exception {

        for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) for(int k=1;k<=N;k++) {
            D[j][k] = Math.min(D[j][k], D[j][i] + D[i][k]);
        }

        for(int K= io.nextInt();K-->0;){
            int s = io.nextInt(), e = io.nextInt();
            io.write(D[s][e] + "\n");
        }

    }

}