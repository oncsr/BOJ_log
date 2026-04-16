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
	
	static int N, M;
	static int[] dp, m, c;
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		m = new int[N];
		c = new int[N];
		for(int i=0;i<N;i++) m[i] = nextInt();
		for(int i=0;i<N;i++) c[i] = nextInt();
		
		dp = new int[10001];
		Arrays.fill(dp, -1);
		
	}
	
	static void solve() throws Exception{
		
		dp[0] = 0;
		for(int i=0;i<N;i++) {
			for(int j=100*(i+1);j>=c[i];j--) if(dp[j-c[i]] != -1) dp[j] = Math.max(dp[j], dp[j-c[i]] + m[i]);
		}
		
		for(int i=0;i<=10000;i++) if(dp[i] >= M) {
			bw.write(i + "\n");
			return;
		}
		
	}
	
}