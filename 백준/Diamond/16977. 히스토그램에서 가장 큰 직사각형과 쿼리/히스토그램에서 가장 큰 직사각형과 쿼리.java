import java.io.*;
import java.util.*;

public class Main {
    static class Node {
        static Node def = new Node(0);
        int len, total, left, right;
        Node(int val) {
            len = 1;
            total = val;
            left = val;
            right = val;
        }
        void update() {
            total = 1;
            left = 1;
            right = 1;
        }
        void update(Node le, Node ri) {
            this.len = le.len + ri.len;
            this.total = Math.max(Math.max(le.total, ri.total), le.right + ri.left);
            this.left = le.left;
            if(le.len == le.total) {
                this.left = le.len + ri.left;
            }
            this.right = ri.right;
            if(ri.len == ri.total) {
                this.right = ri.len + le.right;
            }
        }
    }

    static class SegmentTree {
        Node[] tree;
        SegmentTree(int size) {
            tree = new Node[size*4];
            init(1, size, 1);
        }
        void init(int s, int e, int n) {
            if(s == e) {
                tree[n] = new Node(0);
                return;
            }
            int m = (s+e)>>1;
            init(s,m,n*2);
            init(m+1,e,n*2+1);
            tree[n] = new Node(0);
            tree[n].update(tree[n*2], tree[n*2+1]);
        }

        void update(int s, int e, int i, int n) {
            if(s == e) {
                tree[n].update();
                return;
            }
            int m = (s+e)>>1;
            if(i <= m) update(s,m,i,n*2);
            else update(m+1,e,i,n*2+1);
            tree[n].update(tree[n*2], tree[n*2+1]);
        }

        Node find(int s, int e, int l, int r, int n) {
            if(l>r || l>e || r<s) return Node.def;
            if(l <= s && e <= r) return tree[n];
            int m = (s+e)>>1;
            Node ret = new Node(0);
            ret.update(find(s,m,l,r,n*2), find(m+1,e,l,r,n*2+1));
            return ret;
        }
    }

    static class Query implements Comparable<Query> {
        int num, left, right, width, lo, hi, mid;
        Query(int num, int left, int right, int width, int count) {
            this.num = num;
            this.left = left;
            this.right = right;
            this.width = width;
            this.lo = 0;
            this.hi = count;
            this.mid = (this.lo + this.hi + 1) >> 1;
        }

        @Override
        public int compareTo(Query o) {
            return o.mid - this.mid;
        }
    }
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N, Q;
    static int[][] infos;
    static int[] realLength;
    static Query[] queries;
    static int[] answer;
    static SegmentTree seg;

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());

        infos = new int[N][];
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<N;i++) {
            int a = Integer.parseInt(st.nextToken());
            infos[i] = new int[]{a, i+1};
        }

        Arrays.sort(infos, (a,b) -> b[0]-a[0]);
        int tempCount = 1;
        for(int i=N-2;i>=0;i--) {
            if(infos[i+1][0] != infos[i][0]) tempCount++;
        }
        realLength = new int[tempCount];
        int tempNum = tempCount-1;
        realLength[tempNum] = infos[0][0];
        infos[0][0] = tempNum;
        for(int i=1;i<N;i++) {
            if(infos[i][0] != realLength[infos[i-1][0]]) {
                realLength[--tempNum] = infos[i][0];
            }
            infos[i][0] = tempNum;
        }

        Q = Integer.parseInt(br.readLine());
        queries = new Query[Q];
        answer = new int[Q];
        for(int i=0;i<Q;i++) {
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            queries[i] = new Query(i, l, r, w, tempCount);
        }

        while(true) {
            int diff = 0;
            seg = new SegmentTree(N);
            Arrays.sort(queries);
            int pos = 0;
            for(int i=0;i<Q;i++) if(queries[i].lo < queries[i].hi) {
                diff++;
                while(pos < N && infos[pos][0] >= queries[i].mid) {
                    seg.update(1, N, infos[pos][1], 1);
                    pos++;
                }
                if(seg.find(1, N, queries[i].left, queries[i].right, 1).total >= queries[i].width) {
                    queries[i].lo = queries[i].mid;
                }
                else {
                    queries[i].hi = queries[i].mid - 1;
                }
                queries[i].mid = (queries[i].lo + queries[i].hi + 1) >> 1;
                if(queries[i].lo >= queries[i].hi) {
                    answer[queries[i].num] = realLength[queries[i].mid];
                }
            }

            if(diff == 0) {
                break;
            }
        }

        for(int i=0;i<Q;i++) {
            bw.write(answer[i] + "\n");
        }
        
        bw.close();
    }
}