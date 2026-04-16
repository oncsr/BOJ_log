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
	
	static int N, M;
	static long[][] S;
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		S = new long[N+1][M+1];
		for(int i=1;i<=N;i++) {
			char[] temp = br.readLine().toCharArray();
			for(int j=1;j<=M;j++) {
				int a = temp[j-1]-'0';
				S[i][j] = a + S[i-1][j] + S[i][j-1] - S[i-1][j-1];
			}
		}
		
	}
	
	static void solve() throws Exception{
		
		long ans = -1;
		
		for(int i=1;i<N;i++) {
			for(int j=1;j<M;j++) {
				long A = S[i][j];
				
				long x = S[N][j] - S[i][j];
				long y = S[i][M] - S[i][j];
				long z = S[N][M] - x - y - A;
				ans = Math.max(ans, A*(x*y + z*Math.max(x, y)));
			}
		}
		
		for(int i=1;i<N;i++) {
			for(int j=1;j<M;j++) {
				long A = S[i][M];
				long B = S[N][j] - S[i][j];
				long C = S[N][M] - B - A;
				ans = Math.max(ans, A*B*C);
			}
		}
		
		for(int j=1;j<M;j++) {
			for(int i=1;i<N;i++) {
				long A = S[N][j];
				long B = S[i][M] - S[i][j];
				long C = S[N][M] - A - B;
				ans = Math.max(ans, A*B*C);
			}
		}
		
		for(int i=1;i<N;i++) for(int j=i+1;j<N;j++) {
			long A = S[i][M];
			long B = S[j][M] - A;
			long C = S[N][M] - B - A;
			ans = Math.max(ans, A*B*C);
		}
		
		for(int i=1;i<M;i++) for(int j=i+1;j<M;j++) {
			long A = S[N][i];
			long B = S[N][j] - A;
			long C = S[N][M] - B - A;
			ans = Math.max(ans, A*B*C);
		}
		
		bw.write(ans + "\n");
		
	}
	
}