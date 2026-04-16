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
    static int[] r;

    static int f(int x) {return x==r[x] ? x : (r[x]=f(r[x]));}

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();
    }

    public static void init() throws Exception {

        N = io.nextInt();
        M = io.nextInt();
        r = new int[N+1];
        for(int i=1;i<=N;i++) r[i] = i;

    }

    static void solve() throws Exception {

        while(M-->0) {
            int x = io.nextInt();
            int y = io.nextInt();
            while(f(x) != f(y)) {
                int cur = f(x);
                int next = f(cur+1);
                r[cur] = next;
            }
        }
        boolean[] v = new boolean[N+1];
        int ans = 0;
        for(int i=1;i<=N;i++) {
            int x = f(i);
            if(!v[x]) {
                ans++;
                v[x] = true;
            }
        }

        io.write(ans + "\n");

    }

}