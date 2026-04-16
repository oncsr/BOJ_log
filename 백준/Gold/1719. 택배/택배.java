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

    static final int INF = (int)1e9 + 7;

    static int N, M;
    static int[][] cost, edge;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    static void init() throws Exception {

        N = io.nextInt();
        M = io.nextInt();
        cost = new int[N+1][N+1];
        edge = new int[N+1][N+1];
        for(int i=1;i<=N;i++) {
            Arrays.fill(cost[i], INF);
            Arrays.fill(edge[i], INF);
            cost[i][i] = 0;
            edge[i][i] = 0;
        }
        for(int i=0;i<M;i++) {
            int a = io.nextInt();
            int b = io.nextInt();
            int c = io.nextInt();
            edge[a][b] = Math.min(edge[a][b], c);
            edge[b][a] = Math.min(edge[b][a], c);
            cost[a][b] = cost[b][a] = edge[a][b];
        }

    }

    static void solve() throws Exception {

        for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) for(int k=1;k<=N;k++) cost[j][k] = Math.min(cost[j][k], cost[j][i] + cost[i][k]);
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                if(i == j) {
                    io.write("- ");
                    continue;
                }
                boolean printed = false;
                for(int k=1;k<=N;k++) if(i != k) {
                    if(cost[i][j] == edge[i][k] + cost[k][j] && edge[i][k] != INF) {
                        io.write(k + " ");
                        printed = true;
                        break;
                    }
                }
                if(!printed) io.write("- ");
            }
            io.write("\n");
        }

    }

}