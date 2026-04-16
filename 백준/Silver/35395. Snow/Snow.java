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

    static int N, M, Q;
    static char[][] arr;
    static int[] ans, bot;

    public static void main(String[] args) throws Exception {
        N = IOManager.nextInt();
        M = IOManager.nextInt();
        Q = IOManager.nextInt();
        arr = new char[N][M];
        for(int i=0;i<N;i++) {
            arr[i] = IOManager.nextLine().toCharArray();
        }

        ans = new int[100001];
        bot = new int[M];
        Arrays.fill(bot, N-1);
        for(int i=N-1;i>=0;i--) {
            for(int j=0;j<M;j++) {
                if(arr[i][j] == '*') {
                    ans[bot[j]-i]++;
                    bot[j]--;
                }
            }
        }
        for(int i=1;i<=100000;i++) {
            ans[i] += ans[i-1];
        }

        while(Q-- > 0) {
            IOManager.write(ans[IOManager.nextInt()] + "\n");
        }

        IOManager.close();
    }

}