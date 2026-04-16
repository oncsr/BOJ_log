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
	
	static int N, a, b;
	static int[][] A;
	static boolean[] e;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		a = nextInt();
		b = nextInt();
		A = new int[N+1][2];
		for(int i=1;i<=N;i++) A[i][0] = nextInt();
		for(int i=1;i<=N;i++) A[i][1] = nextInt();
		
	}
	
	static void solve() throws Exception {
		
		e = new boolean[200001];
		for(int i=2;i*i<=200000;i++) if(!e[i]) for(int j=i*i;j<=200000;j+=i) e[j] = true;
		
		int[] dp = new int[N+1];
		dp[1] = cal(A[1][0], A[1][1]);
		for(int i=2;i<=N;i++) {
			dp[i] = Math.max(dp[i-1] + cal(A[i][0], A[i][1]), dp[i-2] + cal(A[i-1][0], A[i][0]) + cal(A[i-1][1], A[i][1]));
		}
		bw.write(dp[N] + "\n");
		
	}
	
	static int cal(int x, int y) {
		return e[x+y] ? b : a;
	}
	
}