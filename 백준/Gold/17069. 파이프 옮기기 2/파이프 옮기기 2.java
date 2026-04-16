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
	
	static int N;
	static int[][] A;
	static long[][][] D;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		A = new int[N+1][N+1];
		D = new long[N+1][N+1][3];
		for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) A[i][j] = nextInt();
		
	}
	
	static void solve() throws Exception{
		
		D[1][2][0] = 1;
		for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(A[i][j] == 0) {
			if(i == 1 && j <= 2) continue;
			D[i][j][0] = D[i][j-1][0] + D[i][j-1][1];
			if(A[i-1][j] == 0 && A[i][j-1] == 0) D[i][j][1] = D[i-1][j-1][0] + D[i-1][j-1][1] + D[i-1][j-1][2];
			D[i][j][2] = D[i-1][j][1] + D[i-1][j][2];
		}
		bw.write((D[N][N][0] + D[N][N][1] + D[N][N][2]) + "\n");
		
	}
	
}