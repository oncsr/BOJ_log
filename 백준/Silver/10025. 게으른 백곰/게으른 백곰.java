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

    static class Bucket implements Comparable<Bucket> {
        int ice, position;
        Bucket(int ice, int position) {
            this.ice = ice;
            this.position = position;
        }

        @Override
        public int compareTo(Bucket o) {
            return this.position - o.position;
        }
    }

    static int N, K;
    static Bucket[] arr;

    public static void main(String[] args) throws Exception {
        N = IOManager.nextInt();
        K = IOManager.nextInt();
        arr = new Bucket[N];

        for (int i = 0; i < N; i++) {
            int ice = IOManager.nextInt();
            int position = IOManager.nextInt();
            arr[i] = new Bucket(ice, position);
        }

        Arrays.sort(arr);
        int ans = 0;
        for (int l = 0, r = 0, s = 0; r < N; r++) {
            s += arr[r].ice;
            while (l < r && arr[r].position - arr[l].position > 2 * K) {
                s -= arr[l++].ice;
            }
            ans = Math.max(ans, s);
        }

        IOManager.write(ans + "\n");
        IOManager.close();
    }
}