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
    static long[] a;
    static long[] seg;
    static long[] seg2;
    static long[] diff;


    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();
    }

    public static void init() throws Exception {

        N = io.nextInt();
        a = new long[N+1];
        diff = new long[N+1];
        for(int i=1;i<=N;i++) {
            a[i] = io.nextLong();
            diff[i] = a[i] - a[i-1];
        }
        seg = new long[N*4];
        seg2 = new long[N*4];

    }

    static void solve() throws Exception {

        init(1,N,1);
        init2(1,N,1);
        Q = io.nextInt();
        while(Q-- > 0) {
            int t = io.nextInt();
            int a = io.nextInt();
            int b = io.nextInt();
            if(t == 0) {
                io.write(gcd(find(1,N,a,1), find2(1,N,a+1,b,1)) + "\n");
            }
            else {
                diff[a] += t;
                update2(1,N,a,1);
                if(b < N) {
                    diff[b+1] -= t;
                    update2(1,N,b+1,1);
                }
                update(1,N,a,b,t,1);
            }
        }

    }

    static long gcd(long a, long b) {
        if(a < b) {
            long temp = a;
            a = b;
            b = temp;
        }
        if(b == 0) return a;
        return a%b==0 ? b : gcd(b, a%b);
    }

    static void init(int s, int e, int n) {
        if(s == e) {
            seg[n] = a[s];
            return;
        }
        int m = (s+e)>>1;
        init(s,m,n*2);
        init(m+1,e,n*2+1);
    }

    static long init2(int s, int e, int n) {
        if(s == e) return seg2[n] = Math.abs(diff[s]);
        int m = (s+e)>>1;
        return seg2[n] = gcd(init2(s,m,n*2), init2(m+1,e,n*2+1));
    }

    static void prop(int s, int e, int n) {
        if(s != e) {
            seg[n*2] += seg[n];
            seg[n*2+1] += seg[n];
            seg[n] = 0;
        }
    }

    static void update(int s, int e, int l, int r, int v, int n) {
        prop(s,e,n);
        if(l>r || l>e || r<s) return;
        if(l<=s && e<=r) {
            seg[n] += v;
            return;
        }
        int m = (s+e)>>1;
        update(s,m,l,r,v,n*2);
        update(m+1,e,l,r,v,n*2+1);
    }

    static void update2(int s, int e, int i, int n) {
        if(s == e) {
            seg2[n] = Math.abs(diff[s]);
            return;
        }
        int m = (s+e)>>1;
        if(i <= m) update2(s,m,i,n*2);
        else update2(m+1,e,i,n*2+1);
        seg2[n] = gcd(seg2[n*2], seg2[n*2+1]);
    }

    static long find(int s, int e, int i, int n) {
        prop(s,e,n);
        if(s == e) return seg[n];
        int m = (s+e)>>1;
        if(i <= m) return find(s,m,i,n*2);
        return find(m+1,e,i,n*2+1);
    }

    static long find2(int s, int e, int l, int r, int n) {
        if(l>r || l>e || r<s) return 0;
        if(l<=s && e<=r) return seg2[n];
        int m = (s+e)>>1;
        return gcd(find2(s,m,l,r,n*2), find2(m+1,e,l,r,n*2+1));
    }

}