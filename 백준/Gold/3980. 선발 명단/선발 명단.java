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

    static int T;
    static int[][] arr;
    static int ans = 0;

    public static void main(String[] args) throws Exception {
        for (T = IOManager.nextInt(); T-- > 0; ) {
            solve();
        }

        IOManager.close();
    }

    public static void solve() throws Exception {
        ans = 0;
        arr = new int[11][11];
        for (int i = 0; i < 11; i++) for (int j = 0; j < 11; j++) {
            arr[i][j] = IOManager.nextInt();
        }
        backtracking(0, 0, 0);
        IOManager.write(ans + "\n");
    }

    public static void backtracking(int cur, int ability, int state) {
        if (cur == 11) {
            ans = Math.max(ans, ability);
            return;
        }
        for (int i = 0; i < 11; i++) if (arr[cur][i] != 0 && (state & (1 << i)) == 0) {
            backtracking(cur + 1, ability + arr[cur][i], state | (1 << i));
        }
    }

}