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

class SegTree {
    int[] sum;
    int[] count;
    int[] tree;
    SegTree(int size) {
        sum = new int[size*4];
        count = new int[size+1];
        tree = new int[size*4];
    }

    void update(int s, int e, int i, int v, int n) {
        if(s == e) {
            sum[n] += v;
            if(v == -1) {
                if(--count[s] == 0) tree[n] = 0;
            }
            else {
                if(count[s]++ == 0) tree[n] = 1;
            }
            return;
        }
        int m = (s+e)>>1;
        if(i <= m) update(s,m,i,v,n*2);
        else update(m+1,e,i,v,n*2+1);
        tree[n] = tree[n*2] + tree[n*2+1];
        sum[n] = sum[n*2] + sum[n*2+1];
    }

    int find(int s, int e, int n) {
        if(s == e) return s;
        int m = (s+e)>>1;
        if(tree[n*2] == m-s+1) return find(m+1,e,n*2+1);
        return find(s,m,n*2);
    }

    int findSum(int s, int e, int l, int r, int n) {
        if(l>r || l>e || r<s) return 0;
        if(l<=s && e<=r) return sum[n];
        int m = (s+e)>>1;
        return findSum(s,m,l,r,n*2) + findSum(m+1,e,l,r,n*2+1);
    }
}

public class Main {

    static IOController io;

    //

    static int Q;
    static SegTree seg;
    static int size = 1000001;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    static void init() throws Exception {

        seg = new SegTree(size+1);

    }

    static void solve() throws Exception {

        for(Q = io.nextInt();Q-->0;) {
            int t = io.nextInt();
            int x = io.nextInt();
            if(t == 1) {
                seg.update(1,size,x,1,1);
            }
            else {
                seg.update(1,size,x,-1,1);
            }
            int mex = seg.find(1,size,1);
            io.write(seg.findSum(1,size,1,mex-1,1) + "\n");
        }

    }

}