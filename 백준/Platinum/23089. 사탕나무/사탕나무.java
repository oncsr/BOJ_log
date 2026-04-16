import java.util.*;
import java.io.*;
    
class Main{
    static StringTokenizer st;
    static int nextInt() throws Exception{
        return Integer.parseInt(st.nextToken());
    }
    static int N, K;
    static int[][] V;
    static int[][][] dp;
    
    static void dfs(int n, int p, int k){
        if(n != 1) dp[n][k][1] = dp[p][k-1][1] + dp[p][k-1][0] - dp[n][k-2][0];
        for(int i:V[n]){
            if(i == p) continue;
            dfs(i,n,k);
            dp[n][k][0] += dp[i][k-1][0];
        }
    }
    
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        st = new StringTokenizer(br.readLine());
        N = nextInt();
        K = nextInt();
        V = new int[N+1][];
        dp = new int[N+1][K+1][2];
        int[] A = new int[N-1];
        int[] B = new int[N-1];
        int[] C = new int[N+1];
        for(int i=0;i<N-1;i++){
            st = new StringTokenizer(br.readLine());
            int a = nextInt(), b = nextInt();
            A[i] = a;
            B[i] = b;
            C[a]++;
            C[b]++;
        }
        for(int i=1;i<=N;i++) {
            V[i] = new int[C[i]];
            dp[i][0][0] = 1;
            dp[i][1][0] = V[i].length-1;
            dp[i][1][1] = 1;
            if(i == 1){
                dp[i][1][0]++;
                dp[i][1][1]--;
            }
        }
        int[] pos = new int[N+1];
        for(int i=0;i<N-1;i++){
            V[A[i]][pos[A[i]]++] = B[i];
            V[B[i]][pos[B[i]]++] = A[i];
        }
        
        for(int k=2;k<=K;k++) dfs(1,0,k);
        int ans = 0;
        for(int i=1;i<=N;i++){
            int res = 0;
            for(int k=0;k<=K;k++) res += dp[i][k][0] + dp[i][k][1];
            ans = Math.max(ans, res);
        }
        bw.write(ans+"\n");
        
        bw.flush();
        bw.close();
    }
}