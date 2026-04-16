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
    static int[][] a;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();
    }

    public static void init() throws Exception {

        N = io.nextInt();
        M = io.nextInt();
        a = new int[N+1][M+1];
        for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
            a[i][j] = io.nextInt() + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }

    }

    static void solve() throws Exception {

        int s = 0, e = Math.min(N, M), m = (s+e+1)>>1;
        while(s < e) {
            if(check(m)) s = m;
            else e = m-1;
            m = (s+e+1)>>1;
        }
        io.write(m + "\n");

    }

    static boolean check(int len) {
        for(int i=len;i<=N;i++) for(int j=len;j<=M;j++) {
            if(a[i][j] - a[i-len][j] - a[i][j-len] + a[i-len][j-len] == 0) return true;
        }
        return false;
    }

}