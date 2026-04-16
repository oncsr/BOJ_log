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

    static int N, M;
    static List<Integer>[] graph, reversedGraph;
    static BitSet visited;
    static Stack<Integer> stack;
    static int[] scc;

    public static int f(int x) {
        return x > N ? x-N : x+N;
    }

    public static void main(String[] args) throws Exception {
        N = IOManager.nextInt();
        M = IOManager.nextInt();
        graph = new List[2*N+1];
        reversedGraph = new List[2*N+1];
        for(int i=1;i<=2*N;i++) {
            graph[i] = new ArrayList<>();
            reversedGraph[i] = new ArrayList<>();
        }

        for(int i=0;i<M;i++) {
            int a = IOManager.nextInt(), b = IOManager.nextInt();
            if(a < 0) {
                a = -a + N;
            }
            if(b < 0) {
                b = -b + N;
            }
            graph[f(a)].add(b);
            reversedGraph[b].add(f(a));
            graph[f(b)].add(a);
            reversedGraph[a].add(f(b));
        }

        stack = new Stack<>();
        visited = new BitSet(2*N+1);
        for(int i=1;i<=2*N;i++) if(!visited.get(i)) {
            visited.set(i);
            dfs1(i);
        }

        int num = 0;
        visited = new BitSet(2*N+1);
        scc = new int[2*N+1];
        while(!stack.isEmpty()) {
            int cur = stack.pop();
            if(visited.get(cur)) {
                continue;
            }
            visited.set(cur);
            dfs2(cur, ++num);
        }

        boolean result = true;
        for(int i=1;i<=N;i++) {
            result &= scc[i] != scc[i+N];
        }

        IOManager.write(result ? "1" : "0");

        IOManager.close();
    }

    public static void dfs1(int cur) {
        for(int nxt : graph[cur]) if(!visited.get(nxt)) {
            visited.set(nxt);
            dfs1(nxt);
        }
        stack.add(cur);
    }

    public static void dfs2(int cur, int num) {
        scc[cur] = num;
        for(int nxt : reversedGraph[cur]) if(!visited.get(nxt)) {
            visited.set(nxt);
            dfs2(nxt, num);
        }
    }

}