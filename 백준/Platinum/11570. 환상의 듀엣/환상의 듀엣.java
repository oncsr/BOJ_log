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
    static final int INF = 2_001_100_002;

    static int N;
    static int[] arr;
    static int[][] dp;

    public static void main(String[] args) throws Exception {
        N = IOManager.nextInt();
        arr = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            arr[i] = IOManager.nextInt();
        }

        dp = new int[N + 1][N + 1];
        for (int i = 0; i <= N; i++) {
            Arrays.fill(dp[i], INF);
        }
        dp[1][0] = 0;
        for (int x = 1; x < N; x++) {
            for (int i = 0; i < x; i++) {
                dp[x + 1][i] = Math.min(dp[x + 1][i], dp[x][i] + Math.abs(arr[x + 1] - arr[x]));
                dp[x + 1][x] = Math.min(dp[x + 1][x], dp[x][i] + (i == 0 ? 0 : Math.abs(arr[x + 1] - arr[i])));
            }
        }

        int ans = INF;
        for (int i = 0; i < N; i++) {
            ans = Math.min(ans, dp[N][i]);
        }

        IOManager.write(ans + "\n");
        IOManager.close();
    }

}