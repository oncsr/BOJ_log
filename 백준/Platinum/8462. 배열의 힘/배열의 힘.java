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

    static int N, T, sq;
    static int[] arr, cnt;
    static long[] ans;
    static int[][] queries;

    public static void main(String[] args) throws Exception {
        N = IOManager.nextInt();
        sq = (int)Math.sqrt(N);
        T = IOManager.nextInt();
        arr = new int[N];
        cnt = new int[1000001];
        for (int i = 0; i < N; i++) {
            arr[i] = IOManager.nextInt();
        }

        queries = new int[T][];
        for (int i = 0; i < T; i++) {
            queries[i] = new int[]{ IOManager.nextInt() - 1, IOManager.nextInt() - 1, i };
        }

        Arrays.sort(queries, (a,b) -> {
            if (a[0] / sq == b[0] / sq) {
                return a[1] - b[1];
            }
            return a[0] / sq - b[0] / sq;
        });

        ans = new long[T];
        long result = 0;
        int pr = -1, pl = 0;
        for (int[] query : queries) {
            int l = query[0], r = query[1], x = query[2];
            while (pr < r) {
                int s = arr[++pr];
                result += (long)s * (2 * cnt[s]++ + 1);
            }
            while (r < pr) {
                int s = arr[pr--];
                result -= (long)s * (2 * cnt[s]-- - 1);
            }
            while (pl < l) {
                int s = arr[pl++];
                result -= (long)s * (2 * cnt[s]-- - 1);
            }
            while (l < pl) {
                int s = arr[--pl];
                result += (long)s * (2 * cnt[s]++ + 1);
            }
            ans[x] = result;
        }

        for (long x : ans) {
            IOManager.write(x + "\n");
        }
        IOManager.close();
    }
}