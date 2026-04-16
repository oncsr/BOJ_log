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

    static int N, M, K;
    static int[][] arr, LU2, RD2, LU, LD, RU, RD;

    public static void main(String[] args) throws Exception {
        N = IOManager.nextInt();
        M = IOManager.nextInt();
        K = IOManager.nextInt();
        arr = new int[N + 2][M + 2];
        LU2 = new int[N + 2][M + 2];
        RD2 = new int[N + 2][M + 2];
        LU = new int[N + 2][M + 2];
        LD = new int[N + 2][M + 2];
        RU = new int[N + 2][M + 2];
        RD = new int[N + 2][M + 2];

        for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) {
            arr[i][j] = IOManager.nextInt() + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }

        for (int i = K; i <= N; i++) for (int j = K; j <= M; j++) {
            LU[i][j] = Math.max(Math.max(LU[i - 1][j], LU[i][j - 1]), rect(i, j));
        }
        for (int i = N - K + 1; i >= 1; i--) for (int j = K; j <= M; j++) {
            LD[i][j] = Math.max(Math.max(LD[i + 1][j], LD[i][j - 1]), rect(i + K - 1, j));
        }
        for (int i = K; i <= N; i++) for (int j = M - K + 1; j >= 1; j--) {
            RU[i][j] = Math.max(Math.max(RU[i - 1][j], RU[i][j + 1]), rect(i, j + K - 1));
        }
        for (int i = N - K + 1; i >= 1; i--) for (int j = M - K + 1; j >= 1; j--) {
            RD[i][j] = Math.max(Math.max(RD[i + 1][j], RD[i][j + 1]), rect(i + K - 1, j + K - 1));
        }
        for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) {
            if (i >= K && j >= 2 * K || i >= 2 * K && j >= K) {
                LU2[i][j] = Math.max(Math.max(LU2[i - 1][j], LU2[i][j - 1]), Math.max(LU[i - K][j], LU[i][j - K]) + rect(i, j));
            }
        }
        for (int i = N; i >= 1; i--) for (int j = M; j >= 1; j--) {
            if (i <= N - K + 1 && j <= M - 2 * K + 1 || i <= N - 2 * K + 1 && j <= M - K + 1) {
                RD2[i][j] = Math.max(Math.max(RD2[i + 1][j], RD2[i][j + 1]), Math.max(RD[i + K][j], RD[i][j + K]) + rect(i + K - 1, j + K - 1));
            }
        }

        int ans = 0;
        for (int i = K; i <= N; i++) for (int j = K; j <= M; j++) {
            int rc = rect(i, j);
            if (i >= 2 * K) {
                ans = Math.max(ans, LU2[i - K][M] + rc);
            }
            if (j >= 2 * K) {
                ans = Math.max(ans, LU2[N][j - K] + rc);
            }
            if (i <= N - K) {
                ans = Math.max(ans, RD2[i + 1][1] + rc);
            }
            if (j <= M - K) {
                ans = Math.max(ans, RD2[1][j + 1] + rc);
            }

            if (i >= 2 * K) {
                int other = Math.max(LD[i - K + 1][j - K], Math.max(LD[i + 1][M], RD[i - K + 1][j + 1]));
                ans = Math.max(ans, rc + LU[i - K][M] + other);
            }
            if (j >= 2 * K) {
                int other = Math.max(RD[i + 1][j - K + 1], Math.max(RD[1][j + 1], RU[i - K][j - K + 1]));
                ans = Math.max(ans, rc + LU[N][j - K] + other);
            }
            if (i <= N - K) {
                int other = Math.max(LU[i][j - K], Math.max(LU[i - K][M], RU[i][j + 1]));
                ans = Math.max(ans, rc + RD[i + 1][1] + other);
            }
            if (j <= M - K) {
                int other = Math.max(LD[i + 1][j], Math.max(LD[1][j - K], LU[i - K][j]));
                ans = Math.max(ans, rc + RD[1][j + 1] + other);
            }

        }
        IOManager.write(ans + "\n");

        IOManager.close();
    }

    public static int rect(int x, int y) {
        if (x < K || y < K) {
            return 0;
        }
        return arr[x][y] - arr[x - K][y] - arr[x][y - K] + arr[x - K][y - K];
    }

}