import java.util.*;
import java.io.*;

class Main{
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        
        int[] A = new int[N];
        int[] B = new int[N];
        for(int i=0;i<N;i++){
            st = new StringTokenizer(br.readLine());
            A[i] = Integer.parseInt(st.nextToken());
            B[i] = Integer.parseInt(st.nextToken());
        }
        
        int[][] dp = new int[K+1][5051];
        for(int i=0;i<=K;i++)for(int j=0;j<=5050;j++) dp[i][j] = -1;
        dp[0][1] = 0;
        
        int ans = 0;
        for(int t=1;t<=K;t++){
            for(int s=1;s<=50*t+1;s++){
                if(dp[t-1][s] != -1){
                    dp[t][s] = Math.max(dp[t][s], dp[t-1][s] + s);
                }
                for(int i=0;i<N;i++){
                    if(s >= B[i] && dp[t-1][s-B[i]] >= A[i]){
                        dp[t][s] = Math.max(dp[t][s], dp[t-1][s-B[i]] - A[i]);
                    }
                }
                if(t == K) ans = Math.max(ans, dp[t][s]);
            }
        }
        bw.write(ans+"\n");
        
        
        bw.flush();
        bw.close();
    }
    
}