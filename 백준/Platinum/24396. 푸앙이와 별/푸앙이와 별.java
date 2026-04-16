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

    static final int INF = 1234567;

    static int N, M;
    static TreeSet<Integer>[] sets;

    public static void main(String[] args) throws Exception {
        N = IOManager.nextInt();
        M = IOManager.nextInt();
        sets = new TreeSet[N + 1];
        for (int i = 1; i <= N; i++) {
            sets[i] = new TreeSet<>();
        }

        for (int i = 1; i <= M; i++) {
            int a = IOManager.nextInt(), b = IOManager.nextInt();
            sets[a].add(b);
            sets[b].add(a);
        }

        Queue<int[]> queue = new ArrayDeque<>();
        int[] dist = new int[N + 1];
        Arrays.fill(dist, INF);
        dist[1] = 0;
        queue.add(new int[]{ 1,0 });
        TreeSet<Integer> remain = new TreeSet<>();
        for (int i = 2; i <= N; i++) remain.add(i);

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            List<Integer> removed = new ArrayList<>();
            for (Integer I : remain) {
                int i = I.intValue();
                if (dist[i] == INF && !sets[cur[0]].contains(i)) {
                    dist[i] = cur[1] + 1;
                    queue.add(new int[]{ i,cur[1] + 1 });
                    removed.add(i);
                }
            }
            for (Integer I : removed) {
                remain.remove(I.intValue());
            }
        }

        for (int i = 1; i <= N; i++) {
            IOManager.write((dist[i] == INF ? -1 : dist[i]) + "\n");
        }
        IOManager.close();
    }

}