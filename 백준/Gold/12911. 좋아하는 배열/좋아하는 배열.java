import java.util.*;
import java.io.*;

class Main {
	
	// IO field
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st = new StringTokenizer("");

	static void nextLine() throws Exception {st = new StringTokenizer(br.readLine());}
	static String nextToken() throws Exception {
		while(!st.hasMoreTokens()) nextLine();
		return st.nextToken();
	}
	static int nextInt() throws Exception { return Integer.parseInt(nextToken()); }
	static long nextLong() throws Exception { return Long.parseLong(nextToken()); }
	static double nextDouble() throws Exception { return Double.parseDouble(nextToken()); }
	static void bwEnd() throws Exception {bw.flush();bw.close();}
	
	// Additional field
	
	static int N, K;
	static long[] dp;
	
	static final long mod = (int)1e9 + 7;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		K = nextInt();
				
	}
	
	static void solve() throws Exception{
		
		
		dp = new long[K+1];
		for(int i=1;i<=K;i++) dp[i] = 1;
		
		for(int i=2;i<=N;i++) {
			long sum = 0;
			for(int j=1;j<=K;j++) sum = (sum + dp[j]) % mod;
			long[] ndp = new long[K+1];
			for(int k=1;k<=K;k++) {
				ndp[k] = sum;
				for(int j=2*k;j<=K;j+=k) ndp[k] = (ndp[k] - dp[j] + mod)%mod;
			}
			dp = ndp;
		}
		long ans = 0;
		for(int i=1;i<=K;i++) ans = (ans + dp[i])%mod;
		bw.write(ans + "\n");
		
		
	}
	
}