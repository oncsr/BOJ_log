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

    static final int[] dx = {1,0,-1,0};
    static final int[] dy = {0,1,0,-1};

    static int N, M;
    static int x1, y1, x2, y2;
    static char[][] A;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();
    }

    public static void init() throws Exception {

        N = io.nextInt();
        M = io.nextInt();
        x1 = io.nextInt()-1;
        y1 = io.nextInt()-1;
        x2 = io.nextInt()-1;
        y2 = io.nextInt()-1;

        A = new char[N][M];
        for(int i=0;i<N;i++) A[i] = io.nextLine().toCharArray();

    }

    static void solve() throws Exception {

        int ans = 1;
        while(true) {
            char[][] newMap = new char[N][M];
            for(int i=0;i<N;i++) for(int j=0;j<M;j++) newMap[i][j] = A[i][j];

            Queue<int[]> q = new LinkedList<>();
            boolean[][] vis = new boolean[N][M];
            q.add(new int[]{x1,y1});
            vis[x1][y1] = true;
            while(!q.isEmpty()) {
                int[] cur = q.poll();
                int x = cur[0], y = cur[1];
                if(x==x2 && y==y2) {
                    io.write(ans + "\n");
                    return;
                }
                for(int k=0;k<4;k++) {
                    int xx = x+dx[k], yy = y+dy[k];
                    if(xx<0 || xx>=N || yy<0 || yy>=M || vis[xx][yy]) continue;
                    if(A[xx][yy] == '1') {
                        newMap[xx][yy] = '0';
                        continue;
                    }
                    vis[xx][yy] = true;
                    q.add(new int[]{xx,yy});
                }
            }
            ans++;
            for(int i=0;i<N;i++) for(int j=0;j<M;j++) A[i][j] = newMap[i][j];
        }

    }

}