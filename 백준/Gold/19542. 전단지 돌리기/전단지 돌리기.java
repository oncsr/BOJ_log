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

    static int N, S, D;
    static int[] d, x;
    static List<Integer>[] V;
    static int ans = -2;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    public static void init() throws Exception {

        N = io.nextInt();
        S = io.nextInt();
        D = io.nextInt();
        d = new int[N+1];
        x = new int[N+1];
        V = new List[N+1];
        for(int i=1;i<=N;i++) V[i] = new ArrayList<>();
        for(int i=1;i<N;i++) {
            int a = io.nextInt(), b = io.nextInt();
            V[a].add(b);
            V[b].add(a);
        }

    }

    static void solve() throws Exception {

        dfs(S, 0, 0);
        io.write(Math.max(0, ans) + "\n");

    }

    static void dfs(int n, int p, int t) {

        d[n] = t;
        x[n] = d[n];
        for(int i:V[n]) if(i != p) {
            dfs(i, n, t+1);
            x[n] = Math.max(x[n], x[i]);
        }
        if(x[n]-t >= D) ans+=2;

    }

}