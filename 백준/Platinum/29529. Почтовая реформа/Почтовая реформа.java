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

    static int N, Q;
    static List<Integer>[] graph, chain;
    static int[] height;
    static int[] chainIndex, chainRoot, depth, parent, size;
    static int[] seg, order, reverseOrder;
    static int cnt = 0;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();
    }

    public static void init() throws Exception {

        N = io.nextInt();
        height = new int[N+1];
        graph = new List[N+1];
        chain = new List[N+1];
        for(int i=1;i<=N;i++) {
            height[i] = io.nextInt();
            graph[i] = new ArrayList<>();
            chain[i] = new ArrayList<>();
        }
        for(int i=1;i<N;i++) {
            int a = io.nextInt();
            int b = io.nextInt();
            graph[a].add(b);
            graph[b].add(a);
        }

        chainIndex = new int[N+1];
        chainRoot = new int[N+1];
        depth = new int[N+1];
        parent = new int[N+1];
        size = new int[N+1];
        seg = new int[N*4];
        order = new int[N+1];
        reverseOrder = new int[N+1];

    }

    static void solve() throws Exception {

        dfs(1,0);
        hld(1,0,1,0);
        init(1,N,1);

        Q = io.nextInt();
        while(Q-- > 0) {
            char o = io.nextToken().charAt(0);
            int a = io.nextInt();
            int b = io.nextInt();
            if(o == '!') {
                update(1,N,order[a],b,1);
            }
            else {
                int result = 0;
                while(chainRoot[a] != chainRoot[b]) {
                    if(depth[a] > depth[b]) {
                        result = Math.max(result, find(1,N,order[chainRoot[a]],order[a],1));
                        a = parent[chainRoot[a]];
                    }
                    else {
                        result = Math.max(result, find(1,N,order[chainRoot[b]],order[b],1));
                        b = parent[chainRoot[b]];
                    }
                }
                if(chainIndex[a] > chainIndex[b]) {
                    result = Math.max(result, find(1,N,order[b],order[a],1));
                }
                else {
                    result = Math.max(result, find(1,N,order[a],order[b],1));
                }

                io.write(result + "\n");
            }
        }

    }

    static int init(int s, int e, int n){
        if(s == e) return seg[n] = height[reverseOrder[s]];
        int m = (s+e)>>1;
        return seg[n] = Math.max(init(s,m,n*2), init(m+1,e,n*2+1));
    }

    static void update(int s, int e, int i, int v, int n) {
        if(s == e) {
            seg[n] = v;
            return;
        }
        int m = (s+e)>>1;
        if(i<=m) update(s,m,i,v,n*2);
        else update(m+1,e,i,v,n*2+1);
        seg[n] = Math.max(seg[n*2], seg[n*2+1]);
    }

    static int find(int s, int e, int l, int r, int n) {
        if(l>r || l>e || r<s) return 0;
        if(l<=s && e<=r) return seg[n];
        int m = (s+e)>>1;
        return Math.max(find(s,m,l,r,n*2), find(m+1,e,l,r,n*2+1));
    }

    static void dfs(int n, int p) {
        size[n] = 1;
        parent[n] = p;
        for(int i:graph[n]) if(i != p) {
            dfs(i,n);
            size[n] += size[i];
        }
    }

    static void hld(int n, int p, int s, int d) {
        depth[n] = d;
        chainRoot[n] = s;
        chainIndex[n] = chain[s].size();
        chain[s].add(n);
        order[n] = ++cnt;
        reverseOrder[cnt] = n;
        int heavy = -1;
        for(int i:graph[n]) if(i != p && (heavy == -1 || size[i] > size[heavy])) {
            heavy = i;
        }

        if(heavy != -1) {
            hld(heavy,n,s,d);
        }
        for(int i:graph[n]) if(i != p && i != heavy) hld(i,n,i,d+1);

    }

}