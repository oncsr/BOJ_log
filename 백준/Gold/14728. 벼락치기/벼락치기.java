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

    static int N, T;
    static int[] k, s;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    public static void init() throws Exception {

        N = io.nextInt();
        T = io.nextInt();
        k = new int[N];
        s = new int[N];
        for (int i = 0; i < N; i++) {
            k[i] = io.nextInt();
            s[i] = io.nextInt();
        }

    }

    static void solve() throws Exception {

        int[] dp = new int[T+1];
        for(int i=0;i<N;i++) {
            for(int j=T;j-k[i]>0;j--) if(dp[j-k[i]] != 0) dp[j] = Math.max(dp[j], dp[j-k[i]] + s[i]);
           if(k[i] <= T) dp[k[i]] = Math.max(dp[k[i]], s[i]);
        }
        int max = 0;
        for(int i=0;i<=T;i++) max = Math.max(max, dp[i]);
        io.write(max + "\n");

    }

}