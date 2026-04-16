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
    int size;
    long[] tree;
    SegTree(int size, int[] arr) {
        this.size = size;
        tree = new long[size*4];
        init(arr, 1, size, 1);
    }
    void init(int[] arr, int s, int e, int n) {
        if(s == e) {
            tree[n] = arr[s];
            return;
        }
        int m=(s+e)>>1;
        init(arr, s, m, n*2);
        init(arr, m+1, e, n*2+1);
        tree[n] = tree[n*2] + tree[n*2+1];
    }
    void update(int s, int e, int i, int v, int n){
        if(s == e) {
            tree[n] += v;
            return;
        }
        int m=(s+e)>>1;
        if(i<=m) update(s,m,i,v,n*2);
        else update(m+1,e,i,v,n*2+1);
        tree[n] =  tree[n*2] + tree[n*2+1];
    }
    long find(int s, int e, int l, int r, int n) {
        if(l>r || l>e || r<s) return 0;
        if(l<=s && e<=r) return tree[n];
        int m=(s+e)>>1;
        return find(s,m,l,r,n*2) + find(m+1,e,l,r,n*2+1);
    }
}

public class Main {

    static IOController io;

    //

    static int N, Q;
    static int[] A, B;
    static SegTree odd, even;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    public static void init() throws Exception {

        N = io.nextInt();
        Q = io.nextInt();
        A = new int[N+1];
        B = new int[N+1];
        for(int i=1;i<=N;i++) {
            if (i % 2 == 1) A[i] = io.nextInt();
            else B[i] = io.nextInt();
        }

    }

    static void solve() throws Exception {

        odd = new SegTree(N, A);
        even = new SegTree(N, B);
        while(Q-- > 0) {
            int o = io.nextInt();
            int a = io.nextInt();
            int b = io.nextInt();
            if(o == 2) {
                if(a%2 == 1) odd.update(1,N,a,b,1);
                else even.update(1,N,a,b,1);
            }
            else {
                long res = Math.abs(odd.find(1,N,a,b,1) - even.find(1,N,a,b,1));
                io.write(res + "\n");
            }
        }

    }

}