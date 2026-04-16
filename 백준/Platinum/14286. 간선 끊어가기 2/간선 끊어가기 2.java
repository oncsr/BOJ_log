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

    static int N, M, S, T;
    static int[][] flow, capacity;
    static int[] level;
    static int answer = 0;

    public static void main(String[] args) throws Exception {
        N = IOManager.nextInt();
        M = IOManager.nextInt();
        flow = new int[N+1][N+1];
        capacity = new int[N+1][N+1];
        for(int i=0;i<M;i++) {
            int a = IOManager.nextInt(), b = IOManager.nextInt(), c = IOManager.nextInt();
            capacity[a][b] += c;
            capacity[b][a] += c;
        }

        S = IOManager.nextInt();
        T = IOManager.nextInt();

        while(bfs(S, T)) while(dfs(S, INF, T) > 0);
        IOManager.write(answer + "\n");

        IOManager.close();
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

    public static int dfs(int cur, int amount, int sink) {
        if(cur == sink) {
            answer += amount;
            return amount;
        }
        for(int nxt=1;nxt<=N;nxt++) {
            int residual = capacity[cur][nxt] - flow[cur][nxt];
            if(level[nxt] == level[cur] + 1 && residual > 0) {
                int min = Math.min(amount, residual);
                int real = dfs(nxt, min, sink);
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