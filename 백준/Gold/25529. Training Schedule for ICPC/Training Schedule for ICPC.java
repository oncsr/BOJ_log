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
	
	static long N, M;
	
	public static void main(String[] args) throws Exception {
		
		N = nextInt();
		M = nextInt();
		while(N>0 || M>0) {
			
			solve();
			
			N = nextInt();
			M = nextInt();
		}
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		
		
	}
	
	static void solve() throws Exception{
		
		long ans = Long.MIN_VALUE;
		
		if(N == 0) {
			bw.write((-M*M) + "\n");
			return;
		}
		if(M <= 1) {
			bw.write((N*N - M) + "\n");
			return;
		}
		
		for(int i=2;i<=Math.min(N+1, M);i++) {
			long k = M/i, cnt = M%i;
			long res = (N-i+2)*(N-i+2) + (i-2) + - (k*k*(i-cnt) + (k+1)*(k+1)*cnt);
			ans = Math.max(ans, res);
		}
		bw.write(ans + "\n");
		
	}
	
}