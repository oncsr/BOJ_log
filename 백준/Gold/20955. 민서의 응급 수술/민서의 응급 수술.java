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

    static int N, M;
    static List<Integer>[] graph;
    static boolean[] vis;
    static int[] deg;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    static void init() throws Exception {

        N = io.nextInt();
        M = io.nextInt();
        graph = new List[N+1];
        deg = new int[N+1];
        for(int i=1;i<=N;i++) graph[i] = new ArrayList<>();
        for(int i=0;i<M;i++) {
            int a = io.nextInt();
            int b = io.nextInt();
            graph[a].add(b);
            graph[b].add(a);
            deg[a]++;
            deg[b]++;
        }
        vis = new boolean[N+1];

    }

    static void solve() throws Exception {

        int ans = -1;
        for(int i=1;i<=N;i++) if(!vis[i]) {
            Queue<Integer> q = new LinkedList<>();
            q.add(i);
            vis[i] = true;
            int cnt = 0, degSum = 0;
            while(!q.isEmpty()) {
                int n = q.poll();
                cnt++;
                degSum += deg[n];
                for(int j:graph[n]) if(!vis[j]) {
                    vis[j] = true;
                    q.add(j);
                }
            }
            ans += (degSum - 2*(cnt-1))/2 + 1;
        }
        io.write(ans + "\n");

    }

}