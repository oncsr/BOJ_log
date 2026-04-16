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
    static int bucketSize = 500, size;
    static int[] odd, even;
    static int[] a;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    static void init() throws Exception {

        N = io.nextInt();
        a = new int[N];
        for(int i=0;i<N;i++) a[i] = io.nextInt()&1;
        size = (N-1)/bucketSize + 1;
        odd = new int[size];
        even = new int[size];

    }

    static void solve() throws Exception {

        for(int i=0;i<N;i++) {
            int bucketNum = i/bucketSize;
            if(a[i] == 0) even[bucketNum]++;
            else odd[bucketNum]++;
        }

        for(M=io.nextInt();M-->0;) {
            int op = io.nextInt();
            if(op == 1) {
                int i = io.nextInt()-1;
                int x = io.nextInt()&1;
                int bucketNum = i/bucketSize;
                if(a[i] == 0) even[bucketNum]--;
                else odd[bucketNum]--;
                a[i] = x;
                if(a[i] == 0) even[bucketNum]++;
                else odd[bucketNum]++;
            }
            else {
                int l = io.nextInt()-1;
                int r = io.nextInt()-1;
                int lNum = l/bucketSize, rNum = r/bucketSize;

                int res = 0;
                for(int i=l;i<Math.min(r+1, (lNum+1)*bucketSize);i++) res += ((op&1)^a[i]) == 0 ? 1 : 0;
                for(int i=lNum+1;i<rNum;i++) res += op == 2 ? even[i] : odd[i];
                if(lNum < rNum) for(int i=rNum*bucketSize;i<=r;i++) res += ((op&1)^a[i]) == 0 ? 1 : 0;
                io.write(res + "\n");
            }
        }

    }

}