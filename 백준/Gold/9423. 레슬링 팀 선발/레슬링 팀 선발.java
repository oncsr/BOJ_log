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
	
	static int N;
	static int sum = 0;
	static int[][] dp;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		dp = new int[45001][101];
		
	}
	
	static void solve() throws Exception{
		
		dp[0][0] = 1;
		for(int i=0;i<N;i++) {
			int a = nextInt();
			sum += a;
			for(int c=i+1;c>=1;c--) for(int k=a;k<=450*c;k++) if(dp[k-a][c-1] == 1) dp[k][c] = 1;
		}
		
		int min = Integer.MAX_VALUE, A = -1, B = -1;
		for(int i=0;i<=45000;i++) if(dp[i][N/2] == 1) {
			int res = Math.abs(i-(sum-i));
			if(res < min) {
				min = res;
				A = Math.min(i, sum-i);
				B = Math.max(i, sum-i);
			}
		}
		bw.write(A + " " + B);
		
	}
	
}