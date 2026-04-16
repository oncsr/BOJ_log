import java.util.*;
import java.io.*;

class Main{
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        
        int[][] arr = new int[N][M];
        for(int i=0;i<N;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<M;j++) arr[i][j] = Integer.parseInt(st.nextToken());
        }
        
        st = new StringTokenizer(br.readLine());
        int sx = Integer.parseInt(st.nextToken());
        int sy = Integer.parseInt(st.nextToken());
        int sd = Integer.parseInt(st.nextToken());
        sx--;
        sy--;
        sd--;
        
        st = new StringTokenizer(br.readLine());
        int ex = Integer.parseInt(st.nextToken());
        int ey = Integer.parseInt(st.nextToken());
        int ed = Integer.parseInt(st.nextToken());
        ex--;
        ey--;
        ed--;
        
        int[][][] vis = new int[N][M][4];
        Queue<Integer> qx = new LinkedList<>();
        Queue<Integer> qy = new LinkedList<>();
        Queue<Integer> qd = new LinkedList<>();
        Queue<Integer> qt = new LinkedList<>();
        
        qx.add(sx);
        qy.add(sy);
        qd.add(sd);
        qt.add(0);
        vis[sx][sy][sd]++;
        
        int[] dx = {0,0,1,-1};
        int[] dy = {1,-1,0,0};
        
        while(!qx.isEmpty()){
            int x = qx.remove();
            int y = qy.remove();
            int d = qd.remove();
            int t = qt.remove();
            if(x == ex && y == ey && d == ed){
                bw.write(t+"\n");
                bw.close();
                return;
            }
            for(int k=1;k<4;k++){
                int nx = x+dx[d]*k;
                int ny = y+dy[d]*k;
                int nd = d;
                int nt = t+1;
                if(nx<0 || nx>=N || ny<0 || ny>=M || arr[nx][ny] == 1) break;
                if(vis[nx][ny][nd]>0) continue;
                qx.add(nx);
                qy.add(ny);
                qd.add(nd);
                qt.add(nt);
                vis[nx][ny][nd]++;
            }
            if(d < 2){
                if(vis[x][y][2] == 0){
                    qx.add(x);
                    qy.add(y);
                    qd.add(2);
                    qt.add(t+1);
                    vis[x][y][2]++;
                }
                if(vis[x][y][3] == 0){
                    qx.add(x);
                    qy.add(y);
                    qd.add(3);
                    qt.add(t+1);
                    vis[x][y][3]++;
                }
            }
            else{
                if(vis[x][y][0] == 0){
                    qx.add(x);
                    qy.add(y);
                    qd.add(0);
                    qt.add(t+1);
                    vis[x][y][0]++;
                }
                if(vis[x][y][1] == 0){
                    qx.add(x);
                    qy.add(y);
                    qd.add(1);
                    qt.add(t+1);
                    vis[x][y][1]++;
                }
            }
            
        }
        
        bw.flush();
        bw.close();
    }
    
}