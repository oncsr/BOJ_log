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

    static int N, root;
    static int[] parent, height;

    public static void main(String[] args) throws Exception {
        N = IOManager.nextInt();
        parent = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            parent[i] = IOManager.nextInt();
            if (parent[i] == -1) {
                root = i;
            }
        }

        height = new int[N + 1];
        Arrays.fill(height, -1);
        height[root] = 0;

        int remain = N - 1, depth = 0;
        while (remain > 0) {
            for (int i = 1; i <= N; i++) if (i != root) {
                if (height[parent[i]] == depth) {
                    height[i] = depth + 1;
                    remain--;
                }
            }
            depth++;
        }

        for (int i = 1; i <= N; i++) {
            IOManager.write(height[i] + "\n");
        }
        IOManager.close();
    }

}