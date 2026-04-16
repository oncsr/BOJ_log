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
	
	static int H, N;
	static int[] dp;
	static int[] h, s;
	
	static final int INF = -(int)1e9 - 7;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		H = nextInt();
		N = nextInt();
		dp = new int[H+1];
		Arrays.fill(dp, INF);
		h = new int[N];
		s = new int[N];
		for(int i=0;i<N;i++) {
			h[i] = nextInt();
			s[i] = nextInt();
		}
		
	}
	
	static void solve() throws Exception{
		
		for(int i=0;i<N;i++) {
			int[] ndp = new int[H+1];
			Arrays.fill(ndp, INF);
			if(h[i] <= H) ndp[h[i]] = s[i];
			for(int j=h[i]+1;j<=H;j++) if(dp[j-h[i]] != INF) {
				int res = Math.min(dp[j-h[i]], s[i]);
				if(ndp[j] == INF) ndp[j] = res;
				else ndp[j] = Math.max(ndp[j], res);
			}
			for(int j=0;j<=H;j++) {
				if(dp[j] == INF) dp[j] = ndp[j];
				else dp[j] = Math.max(dp[j], ndp[j]);
			}
		}
		bw.write(dp[H] + "\n");
		
	}
	
}