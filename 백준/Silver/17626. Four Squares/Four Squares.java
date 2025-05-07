import java.util.*;
import java.io.*;

public class Main {
	
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
	
	static final int INF = 12345;
	static int N;
	static int[] dp;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		dp = new int[N+1];
		Arrays.fill(dp, INF);
		
	}
	
	static void solve() throws Exception {
		
		dp[0] = 0;
		for(int i=1;i*i<=N;i++) {
			for(int j=i*i;j<=N;j++) if(dp[j-i*i] != INF) dp[j] = Math.min(dp[j], dp[j-i*i]+1);  
		}
		bw.write(dp[N] + "\n");
		
	}
	
}