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
    static int[] r, c;
    static int[][] edges, queries;

    static int f(int x) {return x==r[x] ? x : (r[x]=f(r[x]));}

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    static void init() throws Exception {

        N = io.nextInt();
        Q = io.nextInt();
        r = new int[N+1];
        c = new int[N+1];
        for(int i=1;i<=N;i++) {
            r[i] = i;
            c[i] = 1;
        }
        edges = new int[N-1][];
        for(int i=0;i<N-1;i++) edges[i] = new int[]{io.nextInt(),io.nextInt(),io.nextInt()};
        queries = new int[Q][];
        for(int i=0;i<Q;i++) queries[i] = new int[]{io.nextInt(),io.nextInt(),i};

    }

    static void solve() throws Exception {

        Arrays.sort(edges, (a,b) -> b[2]-a[2]);
        Arrays.sort(queries, (a,b) -> b[0]-a[0]);

        int idx = 0;
        int[] ans = new int[Q];
        for(int[] query:queries) {
            while(idx < N-1 && edges[idx][2] >= query[0]) {
                int a = edges[idx][0], b = edges[idx][1];
                int x = f(a), y = f(b);
                if(x != y) {
                    r[x] = y;
                    c[y] += c[x];
                }
                idx++;
            }
            ans[query[2]] = c[f(query[1])] - 1;
        }

        for(int i=0;i<Q;i++) io.write(ans[i] + "\n");

    }

}