import java.util.*;
import java.io.*;

class Main {
	
	// IO field
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;

	static void nextLine() throws Exception {st = new StringTokenizer(br.readLine());}
	static int nextInt() {return Integer.parseInt(st.nextToken());}
	static long nextLong() {return Long.parseLong(st.nextToken());}
	static void bwEnd() throws Exception {bw.flush();bw.close();}
	
	// Additional field

	static int N;
	static int[] dp;
	static final int INF = (int)1e9;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{

		N = Integer.parseInt(br.readLine());
		dp = new int[N+1];
		Arrays.fill(dp, INF);
		
	}
	
	static void solve() throws Exception{

		dp[0] = 0;
		for(int n=3;n<=N;n++) {
			 if(dp[n-3] != INF) dp[n] = dp[n-3] + 1;
			 if(n>=5 && dp[n-5] != INF) dp[n] = Math.min(dp[n], dp[n-5] + 1);
		}
		bw.write((dp[N] == INF ? -1 : dp[N]) + "\n");
		
	}
	
}