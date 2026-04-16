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

    static int N, R;
    static List<int[]>[] v;
    static int S1 = 0, S2 = 0;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();
    }

    public static void init() throws Exception {

        N = io.nextInt();
        R = io.nextInt();
        v = new List[N+1];
        for(int i=1;i<=N;i++) v[i] = new ArrayList<>();
        for(int i=1;i<N;i++) {
            int a = io.nextInt();
            int b = io.nextInt();
            int c = io.nextInt();
            v[a].add(new int[]{b,c});
            v[b].add(new int[]{a,c});
        }

    }

    static void solve() throws Exception {

        dfs(R,0,0);
        io.write(S1 + " " + S2);

    }

    static int dfs(int n, int p, int type) {

        boolean giga = false;
        if(type == 0 && (n == R ? v[n].size() > 1 : v[n].size() > 2)) {
            giga = true;
            type++;
        }

        int res = 0;
        for(int[] e:v[n]) {
            int i = e[0], c = e[1];
            if(i == p) continue;
            res = Math.max(res, dfs(i,n,type) + c);
            if(type == 0) S1 += c;
        }
        if(giga) S2 = res;

        return res;

    }

}