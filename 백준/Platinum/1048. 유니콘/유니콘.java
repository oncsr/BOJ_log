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
	
	static int N, M, L;
	static char[] word;
	static char[][] A;
	
	static int[][] dp;
	static final int mod = (int)1e9 + 7;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		L = nextInt();
		word = br.readLine().toCharArray();
		A = new char[N+1][M+1];
		for(int i=1;i<=N;i++) {
			char[] temp = br.readLine().toCharArray();
			for(int j=1;j<=M;j++) A[i][j] = temp[j-1];
		}
		
	}
	
	static void solve() throws Exception{
		
		dp = new int[N+1][M+1];
		for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) if(A[i][j] == word[0]) dp[i][j] = 1;
		prefixSum();
		
		for(int c=1;c<word.length;c++) {
			int[][] ndp = new int[N+1][M+1];
			for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) if(A[i][j] == word[c]) {
				ndp[i][j] = dp[N][M];
				ndp[i][j] = (ndp[i][j] - rect(Math.max(1,i-1), 1, Math.min(N,i+1), M) + mod) % mod;
				ndp[i][j] = (ndp[i][j] - rect(1, Math.max(1, j-1), N, Math.min(M, j+1)) + mod) % mod;
				ndp[i][j] = (ndp[i][j] + rect(Math.max(1, i-1), Math.max(1, j-1), Math.min(N, i+1), Math.min(M, j+1))) % mod;
				if(valid(i-2,j-2)) ndp[i][j] = (ndp[i][j] - rect(i-2,j-2,i-2,j-2) + mod) % mod;
				if(valid(i-2,j+2)) ndp[i][j] = (ndp[i][j] - rect(i-2,j+2,i-2,j+2) + mod) % mod;
				if(valid(i+2,j-2)) ndp[i][j] = (ndp[i][j] - rect(i+2,j-2,i+2,j-2) + mod) % mod;
				if(valid(i+2,j+2)) ndp[i][j] = (ndp[i][j] - rect(i+2,j+2,i+2,j+2) + mod) % mod;
			}
			dp = ndp;
			prefixSum();
		}
		
		bw.write(dp[N][M] + "\n");
		
	}
	
	static boolean valid(int x, int y) {
		return 1<=x && x<=N && 1<=y && y<=M;
	}
	
	static void prefixSum() {		
		for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
			dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
			dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
			dp[i][j] = (dp[i][j] - dp[i-1][j-1] + mod) % mod;
		}
	}
	
	static int rect(int sx, int sy, int ex, int ey) {
		int res = dp[ex][ey];
		res = (res - dp[sx-1][ey] + mod) % mod;
		res = (res - dp[ex][sy-1] + mod) % mod;
		res = (res + dp[sx-1][sy-1]) % mod;
		return res;
	}
	
}