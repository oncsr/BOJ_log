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

    static int N, P;
    static int ans = 0;
    static List<Integer>[] graph;

    public static void main(String[] args) throws Exception {
        N = IOManager.nextInt();
        P = IOManager.nextInt();
        graph = new List[N+1];
        for(int i=1;i<=N;i++) {
            graph[i] = new ArrayList<>();
        }

        for(int i=0;i<P;i++) {
            int a = IOManager.nextInt(), b = IOManager.nextInt();
            graph[a].add(b);
        }

        Dinic();
        IOManager.write(ans + "\n");

        IOManager.close();
    }

    public static void Dinic() {
        int[][] flow = new int[N+1][N+1];
        int[][] capacity = new int[N+1][N+1];
        for(int i=1;i<=N;i++) for(int j : graph[i]) {
            capacity[i][j] = 1;
        }

        while(true) {
            boolean find = false;

            int[] level = new int[N+1];
            Queue<Integer> queue = new ArrayDeque<>();
            BitSet visited = new BitSet(N+1);
            queue.add(1);
            visited.set(1);
            while(!queue.isEmpty()) {
                int cur = queue.poll();
                if(cur == 2) {
                    find = true;
                }
                for(int nxt=1;nxt<=N;nxt++) {
                    if(capacity[cur][nxt] - flow[cur][nxt] > 0 && !visited.get(nxt)) {
                        visited.set(nxt);
                        queue.add(nxt);
                        level[nxt] = level[cur] + 1;
                    }
                }
            }

            if(!find) {
                break;
            }

            while(dfs(1, INF, flow, capacity, level) > 0);

        }
    }

    public static int dfs(int cur, int amount, int[][] flow, int[][] capacity, int[] level) {
        if(cur == 2) {
            ans++;
            return INF;
        }
        for(int nxt=1;nxt<=N;nxt++) {
            if(level[nxt] == level[cur] + 1 && capacity[cur][nxt] - flow[cur][nxt] > 0) {
                int min = Math.min(amount, capacity[cur][nxt] - flow[cur][nxt]);
                int real = dfs(nxt, min, flow, capacity, level);
                if(real > 0) {
                    flow[cur][nxt] += real;
                    flow[nxt][cur] -= real;
                    return real;
                }
            }
        }
        return 0;
    }
}