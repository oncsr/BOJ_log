import java.io.*;
import java.util.*;

public class Main {

    static class IOManager {
        static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        static StringTokenizer st = new StringTokenizer("");

        private IOManager(){}

        static String nextLine() throws Exception {
            return br.readLine();
        }

        static String nextToken() throws Exception {
            while (!st.hasMoreTokens()) {
                st = new StringTokenizer(nextLine());
            }
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

    static final long MOD = (int)1e9 + 7;

    static int Q;
    static long[] dp;

    public static void main(String[] args) throws Exception {

        dp = new long[10000001];
        dp[1] = 5;
        for(int i=2;i<=10000000;i++) {
            dp[i] = 5 * dp[i-1] % MOD;
        }

        for(Q = IOManager.nextInt(); Q-->0; ) {
            int N = IOManager.nextInt();
            IOManager.write(((dp[N] - dp[N-1] + MOD) % MOD) + "\n");
        }

        IOManager.close();
    }

}