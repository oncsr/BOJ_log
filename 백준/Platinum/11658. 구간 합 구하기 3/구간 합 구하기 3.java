import java.io.*;
import java.util.*;

public class Main {

    static int N;

    static class SegmentTree {
        int[] tree;
        SegmentTree(int[] arr) {
            tree = new int[N * 4];
            init(1, N, 1, arr);
        }

        SegmentTree(SegmentTree left, SegmentTree right) {
            tree = new int[N * 4];
            for(int i=0;i<N*4;i++) {
                tree[i] = left.tree[i] + right.tree[i];
            }
        }

        void init(int s, int e, int n, int[] arr) {
            if(s == e) {
                tree[n] = arr[s];
                return;
            }
            int m = (s+e)>>1;
            init(s, m, n*2, arr);
            init(m+1, e, n*2+1, arr);
            tree[n] = tree[n*2] + tree[n*2+1];
        }

        void update(int s, int e, int i, int v, int n) {
            if(s == e) {
                tree[n] = v;
                return;
            }
            int m = (s+e)>>1;
            if(i <= m) {
                update(s, m, i, v, n*2);
            }
            else {
                update(m+1, e, i, v, n*2+1);
            }
            tree[n] = tree[n*2] + tree[n*2+1];
        }

        int find(int s, int e, int l, int r, int n) {
            if(l>r || l>e || r<s) return 0;
            if(l <= s && e <= r) return tree[n];
            int m = (s+e)>>1;
            return find(s, m, l, r, n*2) + find(m+1, e, l, r, n*2+1);
        }
    }

    static class MultiDimensionalSegmentTree {
        SegmentTree[] tree;
        MultiDimensionalSegmentTree(int[][] arr) {
            tree = new SegmentTree[N * 4];
            init(1, N, 1, arr);
        }

        void init(int s, int e, int n, int[][] arr) {
            if(s == e) {
                tree[n] = new SegmentTree(arr[s]);
                return;
            }
            int m = (s+e)>>1;
            init(s, m, n*2, arr);
            init(m+1, e, n*2+1, arr);
            tree[n] = new SegmentTree(tree[n*2], tree[n*2+1]);
        }

        int update(int s, int e, int v, int x, int y, int n) {
            int ret;
            if(s == e) {
                ret = v - tree[n].find(1, N, y, y, 1);
                tree[n].update(1, N, y, v, 1);
                return ret;
            }
            int m = (s+e)>>1;
            if(x <= m) {
                ret = update(s, m, v, x, y, n*2);
            }
            else {
                ret = update(m+1, e, v, x, y, n*2+1);
            }
            tree[n].update(1, N, y, tree[n].find(1, N, y, y, 1) + ret, 1);
            return ret;
        }

        long find(int s, int e, int x1, int y1, int x2, int y2, int n) {
            if(x1>x2 || x1>e || x2<s) return 0;
            if(x1 <= s && e <= x2) return tree[n].find(1, N, y1, y2, 1);
            int m = (s+e) >> 1;
            return find(s, m, x1, y1, x2, y2, n*2) + find(m+1, e, x1, y1, x2, y2, n*2+1);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st = new StringTokenizer("");

    static MultiDimensionalSegmentTree seg;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[][] temp = new int[N+1][N+1];
        for(int i=1;i<=N;i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=1;j<=N;j++) {
                temp[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        seg = new MultiDimensionalSegmentTree(temp);
        for(int i=0;i<M;i++) {
            st = new StringTokenizer(br.readLine());
            int op = Integer.parseInt(st.nextToken());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            if(op == 0) {
                int c = Integer.parseInt(st.nextToken());
                seg.update(1, N, c, x1, y1, 1);
            }
            else {
                int x2 = Integer.parseInt(st.nextToken());
                int y2 = Integer.parseInt(st.nextToken());
                bw.write(seg.find(1, N, x1, y1, x2, y2, 1) + "\n");
            }
        }

        bw.close();
    }

}