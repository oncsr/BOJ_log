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
    static int[][] fav;
    static int[][] a;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    public static void init() throws Exception {

        N = io.nextInt();
        a = new int[N][N];
        fav = new int[N*N+1][4];

    }

    static void solve() throws Exception {

        for(int i=0;i<N*N;i++) {
            int num = io.nextInt();
            for(int j=0;j<4;j++) fav[num][j] = io.nextInt();

            int favCnt = -1, emptyCnt = -1, resX = 1234, resY = 1234;
            for(int x=0;x<N;x++) for(int y=0;y<N;y++) if(a[x][y] == 0) {
                int favs = 0, empties = 0;
                for(int j=0;j<4;j++) {
                    int xx = x+dx[j], yy = y+dy[j];
                    if(xx<0 || xx>=N || yy<0 || yy>=N) continue;
                    if(a[xx][yy] == 0) empties++;
                    else {
                        for(int k=0;k<4;k++) if(fav[num][k] == a[xx][yy]) favs++;
                    }
                }
                if(favs > favCnt || (favs == favCnt && empties > emptyCnt) || (favs == favCnt && empties == emptyCnt && x < resX) || (favs == favCnt && empties == emptyCnt && x == resX && y < resY)) {
                    favCnt = favs;
                    emptyCnt = empties;
                    resX = x;
                    resY = y;
                }
            }
            a[resX][resY] = num;
        }

        int ans = 0;
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) {
            int cnt = 0;
            for(int k=0;k<4;k++) {
                int x = i+dx[k], y = j+dy[k];
                if(x<0 || x>=N || y<0 || y>=N) continue;
                for(int p=0;p<4;p++) if(fav[a[i][j]][p] == a[x][y]) cnt++;
            }

            if(cnt == 1) ans++;
            if(cnt == 2) ans+=10;
            if(cnt == 3) ans+=100;
            if(cnt == 4) ans+=1000;

        }

        io.write(ans + "\n");

    }

}