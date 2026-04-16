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
    static char[] need = {'B','L','D'};

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();
    }

    public static void init() throws Exception {

        N = io.nextInt();

    }

    static void solve() throws Exception {

        char[] a = ("X" + io.nextToken() + "X").toCharArray();
        N = a.length-2;

        boolean[][] vis = new boolean[N+2][N+2];
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0,N+1,0,0});
        vis[0][N+1] = true;
        int t = 0;
        while(!q.isEmpty()) {
            int[] cur = q.poll();
            int l = cur[0], r = cur[1], c = cur[2];
            t = cur[3];
            if(l+1 == r) continue;
            if(!vis[l+1][r] && need[c]==a[l+1]) {
                vis[l+1][r] = true;
                q.offer(new int[]{l+1,r,(c+1)%3,t+1});
            }
            if(!vis[l][r-1] && need[c]==a[r-1]) {
                vis[l][r-1] = true;
                q.offer(new int[]{l,r-1,(c+1)%3,t+1});
            }
        }

        io.write(t + "\n");

    }

}