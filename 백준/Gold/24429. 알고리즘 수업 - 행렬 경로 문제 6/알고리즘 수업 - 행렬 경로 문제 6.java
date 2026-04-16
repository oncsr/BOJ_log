import java.util.*;
import java.io.*;

class Main{
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        
        int N = Integer.parseInt(br.readLine());
        int[][] A = new int[N+2][N+2];
        
        for(int i=1;i<=N;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=1;j<=N;j++) A[i][j] = Integer.parseInt(st.nextToken());
        }
        
        int P = Integer.parseInt(br.readLine());
        
        int[][] L = new int[P+2][2];
        L[0][0] = 1;
        L[0][1] = 1;
        L[P+1][0] = N;
        L[P+1][1] = N;
        
        for(int i=1;i<=P;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            
            L[i][0] = Integer.parseInt(st.nextToken());
            L[i][1] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(L, new Comparator<int[]>(){
            public int compare(int[] o1, int[] o2){
                if(o1[0] == o2[0]) return o1[1]-o2[1];
                return o1[0]-o2[0];
            }
        });
        
        int ans = A[1][1];
        int[][] D = new int[N+2][N+2];
        for(int k=1;k<=P+1;k++){
            if(L[k][0]<L[k-1][0] || L[k][1]<L[k-1][1]){
                bw.write("-1");
                bw.close();
                return;
            }
            for(int i=L[k][0];i>=L[k-1][0];i--){
                for(int j=L[k][1];j>=L[k-1][1];j--){
                    D[i][j] = Math.max(D[i+1][j], D[i][j+1]) + A[i][j];
                }
            }
            ans += D[L[k-1][0]][L[k-1][1]] - A[L[k-1][0]][L[k-1][1]];
        }
        bw.write(ans+"\n");
        
        bw.flush();
        bw.close();
    }
    
}