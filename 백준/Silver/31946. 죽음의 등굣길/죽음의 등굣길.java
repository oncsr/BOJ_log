import java.util.*;
import java.io.*;

class Main{
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());
        
        int[][] arr = new int[N][M];
        
        for(int i=0;i<N;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=0;j<M;j++) arr[i][j] = Integer.parseInt(st.nextToken());
        }
        
        int X = Integer.parseInt(br.readLine());
        
        int[][] vis = new int[N][M];
        Queue<Integer> qx = new LinkedList<>();
        Queue<Integer> qy = new LinkedList<>();
        qx.add(0);
        qy.add(0);
        vis[0][0]++;
        
        while(!qx.isEmpty()){
            int x = qx.remove();
            int y = qy.remove();
            if(x==N-1 && y==M-1){
                bw.write("ALIVE");
                bw.close();
                return;
            }
            for(int i=Math.max(0,x-X);i<=Math.min(N-1,x+X);i++){
                for(int j=Math.max(0,y-X);j<=Math.min(M-1,y+X);j++){
                    if(Math.abs(x-i)+Math.abs(y-j) > X) continue;
                    if(x == i && y == j) continue;
                    if(vis[i][j] > 0) continue;
                    if(arr[i][j] != arr[0][0]) continue;
                    qx.add(i);
                    qy.add(j);
                    vis[i][j]++;
                }
            }
        }
        bw.write("DEAD");
        
        
        bw.flush();
        bw.close();
    }
    
}