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

    static final int INF = (int)1e9 + 7;

    static int N, M;
    static int[][] edges, origin;
    static int[][] flow, capacity;
    static int[] root, level;

    static int answer = 0;

    public static int find(int x) {
        return x == root[x] ? x : (root[x] = find(root[x]));
    }

    public static void main(String[] args) throws Exception {
        N = IOManager.nextInt();
        M = IOManager.nextInt();

        edges = new int[M][];
        for(int i=0;i<M;i++) {
            int a = IOManager.nextInt(), b = IOManager.nextInt(), c = IOManager.nextInt();
            edges[i] = new int[]{a,b,c};
        }

        int prevWeight = 0;
        Queue<int[]> update = new ArrayDeque<>();
        origin = new int[N+1][N+1];
        root = new int[N+1];
        for(int i=1;i<=N;i++) {
            root[i] = i;
        }
        Arrays.sort(edges, (a,b) -> a[2]-b[2]);
        for(int[] edge : edges) {
            int a = edge[0], b = edge[1], c = edge[2];
            int x = find(a), y = find(b);
            if(c != prevWeight) {
                while(!update.isEmpty()) {
                    int[] now = update.poll();
                    int p = now[0], q = now[1];
                    origin[p][q] = origin[q][p] = 1;
                }
                prevWeight = c;
            }
            if (x != y) {
                root[x] = y;
                update.add(new int[]{a,b});
                continue;
            }
            dinic(a, b);
            update.add(new int[]{a,b});
        }
        IOManager.write(answer + "\n");

        IOManager.close();
    }

    public static void dinic(int source, int sink) {
        flow = new int[N+1][N+1];
        capacity = new int[N+1][N+1];
        for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
            capacity[i][j] = origin[i][j];
        }

        while(bfs(source, sink)) while(dfs(source, sink) > 0);
    }

    public static boolean bfs(int source, int sink) {
        level = new int[N+1];
        Arrays.fill(level, -1);
        level[source] = 0;
        Queue<Integer> queue = new ArrayDeque<>();
        queue.add(source);
        while(!queue.isEmpty()) {
            int cur = queue.poll();
            for(int nxt=1;nxt<=N;nxt++) {
                if(level[nxt] == -1 && capacity[cur][nxt] - flow[cur][nxt] > 0) {
                    level[nxt] = level[cur] + 1;
                    queue.add(nxt);
                }
            }
        }
        return level[sink] != -1;
    }

    public static int dfs(int cur, int sink) {
        if(cur == sink) {
            answer++;
            return 1;
        }
        for(int nxt=1;nxt<=N;nxt++) {
            int residual = capacity[cur][nxt] - flow[cur][nxt];
            if(level[nxt] == level[cur]+1 && residual > 0) {
                if(dfs(nxt, sink) > 0) {
                    flow[cur][nxt]++;
                    flow[nxt][cur]--;
                    return 1;
                }
            }
        }
        return 0;
    }

}