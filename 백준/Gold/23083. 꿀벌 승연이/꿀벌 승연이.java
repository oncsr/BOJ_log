import java.util.*;
import java.io.*;

class Main{
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(br.readLine());
        
        int[][] A = new int[N+2][M+2];
        for(int i=0;i<K;i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            A[x][y] = 1;
        }
        int mod = 1000000007;
        int[][] dp = new int[N+2][M+2];
        dp[1][1] = 1;
        
        for(int j=1;j<=M;j++){
            for(int i=1;i<=N;i++){
                if(i>1 && A[i-1][j] == 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
                if(j%2 == 0){
                    if(j>1 && A[i][j-1] == 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
                    if(i<N && j>1 && A[i+1][j-1] == 0) dp[i][j] = (dp[i][j] + dp[i+1][j-1]) % mod;
                }
                else{
                    if(i>1 && j>1 && A[i-1][j-1] == 0) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
                    if(j>1 && A[i][j-1] == 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
                }
            }
        }
        bw.write(dp[N][M] + "\n");
        
        
        bw.flush();
        bw.close();
    }
    
}