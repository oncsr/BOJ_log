import java.util.*;
import java.io.*;

class Main{
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        
        int[][] arr = new int[N][M];
        int[][] vis = new int[N][M];
        for(int i=0;i<K;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            arr[a][b]++;
        }
        
        int[] dx1 = {-1,-1,0,0,1,1};
        int[] dy1 = {0,1,-1,1,0,1};
        int[] dy2 = {-1,0,-1,1,-1,0};
        Queue<Integer> qx = new LinkedList<>();
        Queue<Integer> qy = new LinkedList<>();
        Queue<Integer> qt = new LinkedList<>();
        
        qx.add(0);
        qy.add(0);
        qt.add(0);
        vis[0][0]++;
        while(!qx.isEmpty()){
            int x = qx.remove();
            int y = qy.remove();
            int t = qt.remove();
            if(x==N-1 && y==M-1){
                bw.write(t+"\n");
                bw.close();
                return;
            }
            for(int i=0;i<6;i++){
                int nx = x+dx1[i];
                int ny = x%2 == 1 ? y+dy1[i] : y+dy2[i];
                int nt = t+1;
                if(nx<0 || nx>=N || ny<0 || ny>=M || vis[nx][ny]>0 || arr[nx][ny]>0) continue;
                qx.add(nx);
                qy.add(ny);
                qt.add(nt);
                vis[nx][ny]++;
            }
        }
        bw.write("-1");
        bw.flush();
        bw.close();
    }
    
}