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

    static int N;
    static int[][] A;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    public static void init() throws Exception {

        N = io.nextInt();
        A = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                A[i][j] = io.nextInt();
            }
        }

    }

    static void solve() throws Exception {

        // 섬에 라벨링하기
        int label = 2;
        boolean[][] vis =  new boolean[N][N];
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(A[i][j] != 0 && !vis[i][j]) {
            Queue<int[]> q = new LinkedList<>();
            q.add(new int[] {i,j});
            vis[i][j] = true;
            while(!q.isEmpty()) {
                int[] curr = q.poll();
                int x = curr[0];
                int y = curr[1];
                A[x][y] = label;
                for(int k=0;k<4;k++) {
                    int xx = x + dx[k];
                    int yy = y + dy[k];
                    if(xx<0 || xx>=N || yy<0 || yy>=N || vis[xx][yy] || A[xx][yy] == 0) continue;
                    q.add(new int[] {xx,yy});
                    vis[xx][yy] = true;
                }
            }
            label++;
        }
        
        int ans = Integer.MAX_VALUE;
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(A[i][j] != 0) {
            for(int x=0;x<N;x++) for(int y=0;y<N;y++) if(A[x][y] != 0 && A[x][y] != A[i][j]) {
                ans = Math.min(ans, Math.abs(i-x) + Math.abs(j-y) - 1);
            }
        }
        io.write(ans + "\n");

    }

}