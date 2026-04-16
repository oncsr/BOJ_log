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

    void nextLine() throws Exception {
        st = new StringTokenizer(br.readLine());
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
    static int C, N;
    static int[] dp;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    public static void init() throws Exception {

        C = io.nextInt();
        N = io.nextInt();
        dp = new int[C+101];
        Arrays.fill(dp, INF);
        dp[0] = 0;

    }

    static void solve() throws Exception {

        while(N-->0) {
            int cost = io.nextInt(), earn = io.nextInt();
            int[] ndp = new int[C+101];
            Arrays.fill(ndp, INF);
            for(int k=1;k*earn<=C+100;k++) {
                for(int i=k*earn;i<=C+100;i++) {
                    if(dp[i-k*earn] != INF) {
                        int res = dp[i-k*earn] + k*cost;
                        ndp[i] = Math.min(ndp[i], res);
                    }
                }
            }
            for(int i=0;i<=C+100;i++) dp[i] = Math.min(dp[i], ndp[i]);
        }
        int ans = INF;
        for(int i=C;i<=C+100;i++) ans = Math.min(ans, dp[i]);
        io.write(ans + "\n");

    }


}