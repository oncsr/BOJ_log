import java.util.*;
import java.io.*;

class Main {
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int R = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        
        int[] dx = {-1,-1,-1,0,0,1,1,1};
        int[] dy = {-1,0,1,-1,1,-1,0,1};
        int[][] arr = new int[R+1][C+1];
        int[][] dp = new int[R+1][C+1];
        int[] X = new int[300001];
        int[] Y = new int[300001];
        for(int i=1;i<=R;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1;j<=C;j++){
                arr[i][j] = Integer.parseInt(st.nextToken());
                dp[i][j] = 1;
                X[arr[i][j]] = i;
                Y[arr[i][j]] = j;
            }
        }
        
        for(int i=300000;i>0;i--){
            if(X[i]==0) continue;
            int x = X[i], y = Y[i];
            int mn = 300001;
            int nx = -1, ny = -1;
            for(int k=0;k<8;k++){
                int xx = x+dx[k], yy = y+dy[k];
                if(xx<1 || xx>R || yy<1 || yy>C) continue;
                if(arr[xx][yy] < mn) {
                    mn = arr[xx][yy];
                    nx = xx;
                    ny = yy;
                }
            }
            if(mn > i) continue;
            dp[nx][ny] += dp[x][y];
            dp[x][y] = 0;
        }
        
        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++) bw.write(dp[i][j] + " ");
            bw.write("\n");
        }
        
        bw.flush();
        bw.close();
    }
}