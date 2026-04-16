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

    static int N, M;
    static int bucketSize, size;
    static long[] a, b;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    static void init() throws Exception {

        N = io.nextInt();
        M = io.nextInt() + io.nextInt();
        a = new long[N];
        for(int i=0;i<N;i++) a[i] = io.nextLong();
        bucketSize = (int)Math.sqrt(N);
        size = (N-1)/bucketSize + 1;
        b = new long[size];

    }

    static void solve() throws Exception {

        for(int i=0;i<N;i++) {
            int bucketNum = i/bucketSize;
            b[bucketNum] += a[i];
        }

        while(M-->0) {
            int op = io.nextInt();
            if(op == 1) {
                int i = io.nextInt()-1;
                long c = io.nextLong();
                int bucketNum = i/bucketSize;
                b[bucketNum] -= a[i];
                a[i] = c;
                b[bucketNum] += a[i];
            }
            else {
                int l = io.nextInt()-1;
                int r = io.nextInt()-1;
                int lNum = l/bucketSize;
                int rNum = r/bucketSize;
                
                long res = 0;
                
                for(int i=l;i<Math.min(r+1, (lNum+1)*bucketSize);i++) res += a[i];
                for(int i=lNum+1;i<rNum;i++) res += b[i];
                if(lNum < rNum) for(int i=rNum*bucketSize;i<=r;i++) res += a[i];
                
                io.write(res + "\n");
            }
        }

    }

}