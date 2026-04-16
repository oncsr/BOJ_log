import java.util.*;
import java.io.*;

class IOController {
    BufferedReader br;
    BufferedWriter bw;
    StringTokenizer st;

    public IOController() {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        st = new StringTokenizer("");
    }

    String nextLine() throws Exception {
        String line = br.readLine();
        st = new StringTokenizer(line);
        return line;
    }

    String nextToken() throws Exception {
        while (!st.hasMoreTokens()) nextLine();
        return st.nextToken();
    }

    int nextInt() throws Exception {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws Exception {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws Exception {
        return Double.parseDouble(nextToken());
    }

    void close() throws Exception {
        bw.flush();
        bw.close();
    }

    void write(String content) throws Exception {
        bw.write(content);
    }

}

public class Main {

    static IOController io;

    //

    static final long INF = (long) 1e18 + 7;

    static int N, M;
    static int[] a;
    static List<int[]>[] graph;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();
    }

    public static void init() throws Exception {

        N = io.nextInt();
        M = io.nextInt();
        a = new int[N];
        graph = new List[N];
        for (int i = 0; i < N; i++) {
            graph[i] = new ArrayList<>();
            a[i] = io.nextInt();
        }
        for (int i = 0; i < M; i++) {
            int a = io.nextInt();
            int b = io.nextInt();
            int c = io.nextInt();
            graph[a].add(new int[]{b, c});
            graph[b].add(new int[]{a, c});
        }

    }

    static void solve() throws Exception {

        PriorityQueue<long[]> pq = new PriorityQueue<>((a, b) -> Long.compare(a[0], b[0]));
        long[] dist = new long[N];
        Arrays.fill(dist, INF);
        dist[0] = 0;
        pq.offer(new long[]{dist[0], 0});
        while (!pq.isEmpty()) {
            long[] cur = pq.poll();
            long d = cur[0];
            int n = (int) cur[1];
            if (d > dist[n]) continue;
            if (n == N - 1) {
                io.write(d + "\n");
                return;
            }
            for (int[] e : graph[n]) if (e[0] == N - 1 || a[e[0]] == 0) {
                if (dist[e[0]] > d + e[1]) {
                    dist[e[0]] = d + e[1];
                    pq.offer(new long[]{dist[e[0]], e[0]});
                }
            }
        }
        io.write("-1");

    }

}