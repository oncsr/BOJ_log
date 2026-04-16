import java.io.*;
import java.util.*;

public class Main {
    static class PersistentUnionFind {
        List<Integer>[] change, parent;
        int[] rank;
        int version;
        PersistentUnionFind(int size) {
            this.version = 0;
            change = new List[size + 1];
            parent = new List[size + 1];
            rank = new int[size + 1];
            for(int i=1;i<=size;i++) {
                change[i] = new ArrayList<>();
                parent[i] = new ArrayList<>();
                change[i].add(0);
                parent[i].add(i);
                rank[i]=1;
            }
        }

        int find(int x, int ver) {
            int s = 0, e = this.change[x].size(), m = (s+e)>>1;
            while(s < e) {
                if(change[x].get(m) >= ver+1) {
                    e = m;
                }
                else {
                    s = m+1;
                }
                m = (s+e)>>1;
            }
            m--;
            return x == parent[x].get(m) ? x : this.find(parent[x].get(m), ver);
        }

        boolean union(int a, int b) {
            int x = this.find(a, version), y = this.find(b, version);
            version++;
            if(x == y) return false;
            if(rank[x] > rank[y]) {
                int temp = x;
                x = y;
                y = temp;
            }
            rank[y] += rank[x];
            parent[x].add(y);
            change[x].add(version);
            return true;
        }
    }

    static class DisjointSet {
        int[] root;
        DisjointSet(int size) {
            root = new int[size+1];
            for(int i=1;i<=size;i++) {
                root[i] = i;
            }
        }

        public int find(int x) {
            return x == root[x] ? x : (root[x] = find(root[x]));
        }

        public boolean union(int a, int b) {
            int x = find(a), y = find(b);
            if(x == y) return false;
            root[x] = y;
            return true;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N, M;
    static int[][] edges;
    static PersistentUnionFind front, back;
    static DisjointSet ds;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        edges = new int[M+1][];
        for(int i=1;i<=M;i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            edges[i] = new int[]{a, b};
        }

        front = new PersistentUnionFind(N);
        for(int i=1;i<=M;i++) {
            int a = edges[i][0], b = edges[i][1];
            front.union(a, b);
        }

        back = new PersistentUnionFind(N);
        for(int i=M;i>=1;i--) {
            int a = edges[i][0], b = edges[i][1];
            back.union(a, b);
        }

        int Q = Integer.parseInt(br.readLine());
        for(int i=0;i<Q;i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            ds = new DisjointSet(N);
            int count = N;
            for(int j=1;j<=N;j++) {
                if(ds.union(j, front.find(j, a-1))) {
                    count--;
                }
                if(ds.union(j, back.find(j, M-b))) {
                    count--;
                }
            }

            bw.write(count + "\n");
        }
        
        bw.close();
    }
}
