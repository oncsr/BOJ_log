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

    static final int MAX = 1_000_000;

    static int N;
    static int[] sieve;
    static int[] cnt;

    public static void main(String[] args) throws Exception {
        N = IOManager.nextInt();
        sieve = new int[MAX + 1];

        for (int i = 2; i * i <= MAX; i++) {
            if (sieve[i] == 0) {
                for (int j = i * i; j <= MAX; j += i) {
                    if (sieve[j] == 0) sieve[j] = i;
                }
            }
        }

        cnt = new int[MAX + 1];
        int odd = 0;
        while (N-- > 0) {
            int a = IOManager.nextInt();
            while (sieve[a] != 0) {
                if (++cnt[sieve[a]] % 2 == 1) {
                    odd++;
                }
                else {
                    odd--;
                }
                a /= sieve[a];
            }
            if (a > 1) {
                if(++cnt[a] % 2 == 1) {
                    odd++;
                }
                else {
                    odd--;
                }
            }
            IOManager.write(odd == 0 ? "DA\n" : "NE\n");
        }

        IOManager.close();
    }
}