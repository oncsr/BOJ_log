import java.io.*;
import java.util.*;

public class Main {
    static class Node {
        static Node zero = new Node();
        static {
            zero.len = 0;
        }

        int len, left, right, total;
        Node() {
            this.len = 1;
            this.left = 0;
            this.right = 0;
            this.total = 0;
        }

        void update(Node a, Node b) {
            this.len = a.len + b.len;
            this.left = a.left;
            if(a.len == a.left) {
                this.left = a.len + b.left;
            }
            this.right = b.right;
            if(b.len == b.right) {
                this.right = b.len + a.right;
            }
            this.total = Math.max(Math.max(a.total, b.total), a.right + b.left);
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
                tree[n] = new Node();
                return;
            }
            int m = (s+e) >> 1;
            init(s, m, n*2);
            init(m+1, e, n*2+1);
            tree[n] = new Node();
            tree[n].update(tree[n*2], tree[n*2+1]);
        }

        void update(int s, int e, int i, int v, int n) {
            if(s == e) {
                tree[n].left = v;
                tree[n].right = v;
                tree[n].total = v;
                return;
            }
            int m = (s+e) >> 1;
            if(i <= m) {
                update(s, m, i, v, n*2);
            }
            else {
                update(m+1, e, i, v, n*2+1);
            }
            tree[n].update(tree[n*2], tree[n*2+1]);
        }

        Node find(int s, int e, int l, int r, int n) {
            if(l>r || l>e || r<s) return Node.zero;
            if(l <= s && e <= r) return tree[n];
            int m = (s+e) >> 1;
            Node ret = new Node();
            ret.update(find(s, m, l, r, n*2), find(m+1, e, l, r, n*2+1));
            return ret;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N, Q;
    static int[] diff;
    static SegmentTree[] seg;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());

        diff = new int[N+2];
        int prev = 1_234_567_890;
        st = new StringTokenizer(br.readLine());
        for(int i=1;i<=N;i++) {
            int a = Integer.parseInt(st.nextToken());
            diff[i] = a - prev;
            prev = a;
        }

        seg = new SegmentTree[11];
        for(int i=1;i<=10;i++) {
            seg[i] = new SegmentTree(N);
        }

        for(int i=2;i<=N;i++) {
            if(1 <= Math.abs(diff[i]) && Math.abs(diff[i]) <= 10) {
                seg[Math.abs(diff[i])].update(1, N, i, 1, 1);
            }
        }

        for(int i=0;i<Q;i++) {
            st = new StringTokenizer(br.readLine());
            int op = Integer.parseInt(st.nextToken());
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            if(op == 1) {
                if(1 <= Math.abs(diff[l]) && Math.abs(diff[l]) <= 10) {
                    seg[Math.abs(diff[l])].update(1, N, l, 0, 1);
                }
                diff[l] += x;
                if(1 <= Math.abs(diff[l]) && Math.abs(diff[l]) <= 10) {
                    seg[Math.abs(diff[l])].update(1, N, l, 1, 1);
                }

                if(r < N) {
                    if(1 <= Math.abs(diff[r+1]) && Math.abs(diff[r+1]) <= 10) {
                        seg[Math.abs(diff[r+1])].update(1, N, r+1, 0, 1);
                    }
                    diff[r+1] -= x;
                    if(1 <= Math.abs(diff[r+1]) && Math.abs(diff[r+1]) <= 10) {
                        seg[Math.abs(diff[r+1])].update(1, N, r+1, 1, 1);
                    }
                }
            }
            else {
                if(l == r) bw.write("1\n");
                else bw.write((seg[x].find(1, N, l+1, r, 1).total + 1) + "\n");
            }
        }
        
        bw.close();
    }
}