import java.math.BigInteger;
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

    static int N;
    static int[] A, C, I, P;
    static int len;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    public static void init() throws Exception {

        N = io.nextInt();
        A = new int[N];
        for(int i=0;i<N;i++) A[i] = io.nextInt();
        C = new int[N];
        I = new int[N];
        P = new int[N];

    }

    static void solve() throws Exception {

        int mx = 0, idx = 0;
        for(int i=0;i<N;i++) {
            int p = lowerBound(A[i]);
            if(p == 0) P[i] = -1;
            else P[i] = I[p-1];
            C[p] = A[i];
            I[p] = i;
            if(len == p) len++;
            if(len > mx) {
                mx = len;
                idx = i;
            }
        }

        Stack<Integer> S = new Stack<>();
        while(idx != -1) {
            S.add(A[idx]);
            idx = P[idx];
        }

        io.write(S.size() + "\n");
        while(!S.isEmpty()) io.write(S.pop() + " ");

    }

    static int lowerBound(int a) {
        int s = 0, e = len, m = (s+e)>>1;
        while(s<e) {
            if(C[m] < a) s = m+1;
            else e = m;
            m = (s+e)>>1;
        }
        return m;
    }

}