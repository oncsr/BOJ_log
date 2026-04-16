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

    static int N;
    static List<Integer>[] graph;
    static int[][] par;
    static int[] depth;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    public static void init() throws Exception {

        N = io.nextInt();
        graph = new List[N+1];
        for(int i=1;i<=N;i++) graph[i] = new ArrayList<>();
        for(int i=1;i<N;i++) {
            int a = io.nextInt();
            int b = io.nextInt();
            graph[a].add(b);
            graph[b].add(a);
        }
        par = new int[N+1][18];
        depth = new int[N+1];

    }

    static void solve() throws Exception {

        dfs(1,0,0);
        for(int k=1;k<18;k++) for(int i=1;i<=N;i++) par[i][k] = par[par[i][k-1]][k-1];

        for(int q=io.nextInt();q-->0;) {
            int o = io.nextInt();
            int i = io.nextInt();
            int j = io.nextInt();
            int k = io.nextInt();
            if(o == 2) {
                int l = io.nextInt();
                if(depth[k] < depth[l]) k = l;
            }
            if((lca(i,k) == k || lca(j,k) == k) && lca(k, lca(i,j)) == lca(i,j) && !(o == 2 && k == lca(i,j))) {
                io.write("NO\n");
            }
            else{
                io.write("YES\n");
            }
        }

    }

    static void dfs(int n, int p, int d) {
        par[n][0] = p;
        depth[n] = d;
        for(int i:graph[n]) if(i != p) dfs(i,n,d+1);
    }

    static int lca(int a, int b) {
        int diff = Math.abs(depth[a] - depth[b]);
        for(int k=0;k<18;k++) if((diff & (1<<k)) != 0) {
            if(depth[a] > depth[b]) a = par[a][k];
            else b = par[b][k];
        }

        if(a == b) return a;
        for(int k=17;k>=0;k--) if(par[a][k] != par[b][k]) {
            a = par[a][k];
            b = par[b][k];
        }

        if(a != b) a = par[a][0];
        return a;
    }

}