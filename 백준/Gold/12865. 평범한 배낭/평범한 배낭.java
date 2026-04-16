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
	static int[] dp;
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		K = nextInt();
		dp = new int[K+1];
		Arrays.fill(dp, -1);
		
	}
	
	static void solve() throws Exception{
		
		dp[0] = 0;
		for(int i=0;i<N;i++) {
			int w = nextInt(), v = nextInt();
			for(int j=K;j>=w;j--) if(dp[j-w] != -1) dp[j] = Math.max(dp[j], dp[j-w]+v);
		}
		
		int ans = 0;
		for(int i=0;i<=K;i++) ans = Math.max(ans, dp[i]);
		bw.write(ans + "\n");
		
	}
	
}