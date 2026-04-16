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

    static int N, L, R;
    static int[][] A;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    public static void init() throws Exception {

        N = io.nextInt();
        L = io.nextInt();
        R = io.nextInt();
        A = new int[N][N];
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) A[i][j] = io.nextInt();

    }

    static void solve() throws Exception {

        int ans = 0;
        while(true) {
            boolean changed = false;
            boolean[][] vis = new boolean[N][N];
            int[][] newMap = new int[N][N];
            for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(!vis[i][j]) {
                Queue<int[]> q = new LinkedList<>();
                q.add(new int[]{i,j});
                List<int[]> list = new ArrayList<>();
                vis[i][j] = true;
                int sum = 0, cnt = 0;
                while(!q.isEmpty()) {
                    int[] now = q.poll();
                    int x = now[0], y = now[1];
                    list.add(new int[]{x,y});
                    sum += A[x][y];
                    cnt++;
                    for(int k=0;k<4;k++) {
                        int xx = x+dx[k], yy = y+dy[k];
                        if(xx<0 || xx>=N || yy<0 || yy>=N || vis[xx][yy] || Math.abs(A[x][y]-A[xx][yy]) < L || Math.abs(A[x][y]-A[xx][yy]) > R) continue;
                        q.add(new int[]{xx,yy});
                        vis[xx][yy] = true;
                    }
                }
                sum /= cnt;
                for(int[] item:list) {
                    int x = item[0], y = item[1];
                    if(A[x][y] != sum) changed = true;
                    newMap[x][y] = sum;
                }
            }
            if(!changed) break;
            ans++;
            for(int i=0;i<N;i++) for(int j=0;j<N;j++) A[i][j] = newMap[i][j];

        }
        io.write(ans + "\n");

    }

}