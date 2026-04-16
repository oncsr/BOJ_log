import java.io.*;
import java.util.*;

class DisjointSet {
    int[] root;
    DisjointSet(int size) {
        root = new int[size+1];
        for(int i=1;i<=size;i++) {
            root[i] = i;
        }
    }

    int find(int x) {
        return x == root[x] ? x : (root[x] = find(root[x]));
    }

    boolean union(int a, int b) {
        int x = find(a), y = find(b);
        if(x == y) return false;
        root[x] = y;
        return true;
    }
}

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N, M;
    static int[][] edges;
    static List<int[]>[] tree;
    static int[] parent, edgeNum, depth;
    static DisjointSet ds;
    static BitSet bs1, bs2;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        tree = new List[N+1];
        for(int i=1;i<=N;i++) {
            tree[i] = new ArrayList<>();
        }
        edges = new int[M][];
        ds = new DisjointSet(N);
        bs1 = new BitSet(M);
        bs2 = new BitSet(M);
        for(int i=0;i<M;i++) {
            st = new StringTokenizer(br.readLine());
            edges[i] = new int[]{Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())};
            int a = edges[i][0], b = edges[i][1];
            if(ds.union(a, b)) {
                tree[a].add(new int[]{b,i});
                tree[b].add(new int[]{a,i});
            }
            else {
                bs1.set(i);
                bs2.set(i);
            }
        }

        parent = new int[N+1];
        edgeNum = new int[N+1];
        depth = new int[N+1];
        for(int i=1;i<=N;i++) if(parent[i] == 0) {
            dfs(i, 0, 0);
        }

        ds = new DisjointSet(N);
        for(int i=0;i<M;i++) if(bs2.get(i)) {
            int a = ds.find(edges[i][0]), b = ds.find(edges[i][1]);
            while(a != b) {
                if(depth[a] > depth[b]) {
                    int temp = a;
                    a = b;
                    b = temp;
                }
                if(!bs1.get(edgeNum[b])) {
                }
                bs1.set(edgeNum[b]);
                ds.union(b, parent[b]);
                b = ds.find(parent[b]);
            }
        }

        List<int[]> answer = new ArrayList<>();
        for(int i=0;i<M;i++) if(!bs1.get(i)) {
            int min = Math.min(edges[i][0], edges[i][1]);
            int max = Math.max(edges[i][0], edges[i][1]);
            answer.add(new int[]{min, max});
        }
        Collections.sort(answer, (a,b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        bw.write(answer.size() + "\n");
        for(int[] edge : answer) {
            bw.write(edge[0] + " " + edge[1] + "\n");
        }
        bw.close();
    }

    public static void dfs(int cur, int par, int dep) {
        parent[cur] = par;
        depth[cur] = dep;
        for(int[] edge : tree[cur]) if(edge[0] != par) {
            edgeNum[edge[0]] = edge[1];
            dfs(edge[0], cur, dep+1);
        }
    }

}