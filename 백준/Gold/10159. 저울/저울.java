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
    static boolean[][] G, R;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    public static void init() throws Exception {

        N = io.nextInt();
        M = io.nextInt();
        G = new boolean[N+1][N+1];
        R = new boolean[N+1][N+1];
        for(int i=0;i<M;i++) {
            int a = io.nextInt();
            int b = io.nextInt();
            G[a][b] = true;
            R[b][a] = true;
        }

    }

    static void solve() throws Exception {

        for(int i=1;i<=N;i++) {
            boolean[] vis = new boolean[N+1];
            vis[i] = true;
            Queue<Integer> q = new ArrayDeque<>();
            q.add(i);
            while(!q.isEmpty()) {
                int n = q.poll();
                for(int j=1;j<=N;j++) if(G[n][j] && !vis[j]) {
                    vis[j] = true;
                    q.add(j);
                }
            }

            q.add(i);
            while(!q.isEmpty()) {
                int n = q.poll();
                for(int j=1;j<=N;j++) if(R[n][j] && !vis[j]) {
                    vis[j] = true;
                    q.add(j);
                }
            }

            int ans = 0;
            for(int j=1;j<=N;j++) if(!vis[j]) ans++;
            io.write(ans + "\n");
        }

    }

}