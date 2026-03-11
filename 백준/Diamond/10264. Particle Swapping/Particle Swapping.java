import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static class Point {
        int x, y;
        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
        int dist(Point o) {
            return (this.x - o.x) * (this.x - o.x) + (this.y - o.y) * (this.y - o.y);
        }
    }

    static int N, M, Q;
    static Point[] points;
    static int[][] edges;
    static List<Integer>[] adjacentList;
    static int[][] queries;

    static int[] val;
    static List<int[]> realEdges;
    static int[] root;
    static List<Integer>[] graph;
    static int[] depth;
    static int[][] parent, safeness;

    public static int find(int x) {
        return x == root[x] ? x : (root[x] = find(root[x]));
    }

    public static void main(String[] args) throws Exception {
        // 0. Input

        N = Integer.parseInt(br.readLine());
        points = new Point[N];
        for(int i=0;i<N;i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            points[i] = new Point(x, y);
        }

        M = Integer.parseInt(br.readLine());
        adjacentList = new List[N];
        for(int i=0;i<N;i++) {
            adjacentList[i] = new ArrayList<>();
        }
        edges = new int[M][];
        for(int i=0;i<M;i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            adjacentList[a].add(b);
            adjacentList[b].add(a);
        }

        Q = Integer.parseInt(br.readLine());
        queries = new int[Q][];
        for(int i=0;i<Q;i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            int aa = a*N + b;
            int bb = b*N + a;
            queries[i] = new int[]{aa,bb};
        }

        // 1. State Graph Modeling

        /// 1-0. Find State Graph Weight
        val = new int[N*N];
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) {
            val[i*N + j] = points[i].dist(points[j]);
        }

        /// 1-1. Find Edges of State Graph
        realEdges = new ArrayList<>();
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) {
            if(i == j) continue;
            int node1 = i*N + j;
            for(int k : adjacentList[j]) if(i != k) {
                int node2 = i*N + k;
                int cost = Math.min(val[node1], val[node2]);
                realEdges.add(new int[]{node1, node2, cost});
            }
            for(int k : adjacentList[i]) if(j != k) {
                int node2 = k*N + j;
                int cost = Math.min(val[node1], val[node2]);
                realEdges.add(new int[]{node1, node2, cost});
            }
        }

        /// 1-2. Construct State Graph's MST
        root = new int[N*N];
        graph = new List[N*N];
        for(int i=0;i<N*N;i++) {
            root[i] = i;
            graph[i] = new ArrayList<>();
        }
        Collections.sort(realEdges, (a, b) -> b[2]-a[2]);
        for(int[] edge : realEdges) {
            int a = edge[0], b = edge[1], c = edge[2];
            int x = find(a), y = find(b);
            if(x == y) continue;
            root[x] = y;
            graph[a].add(b);
            graph[b].add(a);
        }

        /// 1-3. Construct Sparse Graph (For Path Query)
        depth = new int[N*N];
        parent = new int[N*N][18];
        safeness = new int[N*N][18];
        dfs(1, 0, 0);
        for(int k=1;k<18;k++) for(int i=1;i<N*N;i++) {
            parent[i][k] = parent[parent[i][k-1]][k-1];
            safeness[i][k] = Math.min(safeness[i][k-1], safeness[parent[i][k-1]][k-1]);
        }

        // 2. Solve Queries
        for(int[] query : queries) {
            int a = query[0], b = query[1];

            int answer = (int)1e9 + 7;
            int depthDiff = Math.abs(depth[a] - depth[b]);
            for(int i=0;i<18;i++) if((depthDiff & (1<<i)) != 0) {
                if(depth[a] > depth[b]) {
                    answer = Math.min(answer, safeness[a][i]);
                    a = parent[a][i];
                }
                else {
                    answer = Math.min(answer, safeness[b][i]);
                    b = parent[b][i];
                }
            }

            for(int i=17;i>=0;i--) if(parent[a][i] != parent[b][i]) {
                answer = Math.min(answer, Math.min(safeness[a][i], safeness[b][i]));
                a = parent[a][i];
                b = parent[b][i];
            }

            if(a != b) {
                answer = Math.min(answer, Math.min(val[a], val[b]));
                a = parent[a][0];
            }
            answer = Math.min(answer, val[a]);
            bw.write(Math.sqrt(answer) + "\n");
        }
        bw.close();
    }

    public static void dfs(int cur, int par, int dep) {
        parent[cur][0] = par;
        depth[cur] = dep;
        safeness[cur][0] = val[cur];
        for(int nxt : graph[cur]) if(nxt != par) {
            dfs(nxt, cur, dep+1);
        }
    }
}
