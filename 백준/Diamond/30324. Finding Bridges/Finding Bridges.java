import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static class DisjointSet {
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

    static int N, M, Q;
    static int[][] edges;
    static int[] parent, depth;
    static List<Integer>[] graph;
    static DisjointSet ds1, ds2;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());

        TreeSet<String> set = new TreeSet<>();
        for(int i=0;i<M;i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if(a > b) {
                int c = a;
                a = b;
                b = c;
            }
            set.add(a + "," + b);
        }

        Stack<int[]> stack = new Stack<>();
        for(int i=0;i<Q;i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if(a > b) {
                int c = a;
                a = b;
                b = c;
            }
            stack.add(new int[]{a,b});
            set.remove(a + "," + b);
        }

        edges = new int[M][];
        int idx = 0;
        for(String s : set) {
            String[] splt = s.split(",");
            int a = Integer.parseInt(splt[0]);
            int b = Integer.parseInt(splt[1]);
            edges[idx++] = new int[]{a,b};
        }

        while(!stack.isEmpty()) {
            edges[idx++] = stack.pop();
        }

        // 1. Building Forest

        graph = new List[N+1];
        for(int i=1;i<=N;i++) {
            graph[i] = new ArrayList<>();
        }

        ds1 = new DisjointSet(N);
        for(int[] edge : edges) {
            int a = edge[0], b = edge[1];
            if(ds1.union(a,b)) {
                graph[a].add(b);
                graph[b].add(a);
            }
        }

        // 2. DFS

        parent = new int[N+1];
        depth = new int[N+1];
        for(int i=1;i<=N;i++) if(parent[i] == 0) {
            dfs(i, 0, 0);
        }

        // 3. Disjoint Set

        ds1 = new DisjointSet(N);
        ds2 = new DisjointSet(N);

        Stack<Integer> answer = new Stack<>();
        int count = 0;
        if (M == Q) {
            answer.add(0);
        }
        for(int i=0;i<M-1;i++) {
            int a = edges[i][0], b = edges[i][1];
            if(ds1.union(a, b)) {
                count++;
            }
            else {
                a = ds2.find(a);
                b = ds2.find(b);
                while(a != b) {
                    if(depth[a] > depth[b]) {
                        ds2.union(a, parent[a]);
                        a = ds2.find(a);
                    }
                    else {
                        ds2.union(b, parent[b]);
                        b = ds2.find(b);
                    }
                    count--;
                }
            }
            if(i >= M-Q-1) {
                answer.add(count);
            }
        }

        while(!answer.isEmpty()) {
            int s = answer.pop();
            bw.write(s + "\n");
        }
        bw.close();

    }

    public static void dfs(int cur, int par, int dep) {
        parent[cur] = par;
        depth[cur] = dep;
        for(int nxt : graph[cur]) if(nxt != par) {
            dfs(nxt, cur, dep + 1);
        }
    }

}
