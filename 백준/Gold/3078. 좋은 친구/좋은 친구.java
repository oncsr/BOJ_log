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

    static int N, K;
    static int[] l;
    static int[][] a;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();
    }

    public static void init() throws Exception {

        N = io.nextInt();
        K = io.nextInt();
        l = new int[N+1];
        a = new int[N+1][21];
        for(int i=1;i<=N;i++) {
            int len = io.nextToken().length();
            l[i] = len;
            a[i][len]++;
            for(int j=1;j<=20;j++) a[i][j] += a[i-1][j];
        }

    }

    static void solve() throws Exception {

        long ans = 0;
        for(int i=1;i<=N;i++) {
            int len = l[i];
            ans += a[i+K <= N ? i+K : N][len] - a[i][len];
        }
        io.write(ans + "\n");

    }

}