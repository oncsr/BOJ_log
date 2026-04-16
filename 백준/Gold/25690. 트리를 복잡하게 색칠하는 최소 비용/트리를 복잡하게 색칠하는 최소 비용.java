import java.util.*;
import java.io.*;

class Main{
    
    static int[][] V = new int[100000][];
    static int[] B = new int[100000];
    static int[] W = new int[100000];
    static long[][] dp = new long[100000][2];
    
    static void dfs(int n){
        dp[n][0] = B[n];
        dp[n][1] = W[n];
        for(int i:V[n]){
            dfs(i);
            dp[n][0] += dp[i][1];
            dp[n][1] += Math.min(dp[i][0], dp[i][1]);
        }
    }
    
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int N = Integer.parseInt(br.readLine());
        
        int[] P = new int[N-1];
        int[] C = new int[N-1];
        int[] cnt = new int[N];
        for(int i=0;i<N-1;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            P[i] = Integer.parseInt(st.nextToken());
            C[i] = Integer.parseInt(st.nextToken());
            cnt[P[i]]++;
        }
        
        int[] pos = new int[N];
        for(int i=0;i<N;i++){
            V[i] = new int[cnt[i]];
        }
        
        for(int i=0;i<N-1;i++){
            int p = P[i], c = C[i];
            V[p][pos[p]] = c;
            pos[p]++;
        }
        
        for(int i=0;i<N;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            W[i] = Integer.parseInt(st.nextToken());
            B[i] = Integer.parseInt(st.nextToken());
        }
        
        dfs(0);
        bw.write(Math.min(dp[0][0], dp[0][1])+"\n");
        
        bw.flush();
        bw.close();
    }
}