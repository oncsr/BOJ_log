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
	static int[][] A;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		A = new int[N][2];
		for(int i=0;i<N;i++) A[i] = new int[] {nextInt(), nextInt()};
		
	}
	
	static void solve() throws Exception{
		
		Arrays.sort(A, (a,b) -> Math.max(-a[1], a[0]-b[1]) - Math.max(b[0] - a[1], -b[1]));
		long ans = Long.MIN_VALUE, S = 0;
		for(int i=0;i<N;i++) {
			ans = Math.max(ans, S-A[i][1]);
			S += A[i][0];
		}
		bw.write(ans + "\n");
		
	}
	
}