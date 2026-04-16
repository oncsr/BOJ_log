import java.util.*;
import java.io.*;

class Main{
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        
        int N = Integer.parseInt(br.readLine());
        
        long[][][] dp = new long[3*N+1][3*N+1][3*N+1];
        
        dp[1][1][0] = 1L;
        dp[1][0][1] = 1L;
        long ans = 0L;
        for(int n=2;n<=3*N;n++){
            if(n%3 == 2){
                // lunch
                for(int i=0;i<=n;i++){
                    int j = n-i;
                    if(i > 0 && i%3 == 2)   dp[n][i][j] += dp[n-1][i-1][j];
                    if(j > 0 && j%3 == 2)   dp[n][i][j] += dp[n-1][i][j-1];
                }
                
            }
            else{
                for(int i=0;i<=n;i++){
                    int j = n-i;
                    if(i > 0 && i%3 != 2) dp[n][i][j] += dp[n-1][i-1][j];
                    if(j > 0 && j%3 != 2) dp[n][i][j] += dp[n-1][i][j-1];
                    if(n == 3*N)    ans += dp[n][i][j];
                }
            }
        }
        bw.write((ans/2) + "\n");
        bw.flush();
        bw.close();
    }
    
}