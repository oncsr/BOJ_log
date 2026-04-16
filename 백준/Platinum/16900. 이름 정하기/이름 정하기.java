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
	
	static int N, K;
	static char[] S;
	static int[] X;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		S = nextToken().toCharArray();
		K = nextInt();
		N = S.length;
		X = new int[N];

	}
	
	static void solve() throws Exception{
		
		for(int i=1;i<N;i++) {
			X[i] = X[i-1];
			while(X[i]>0 && S[X[i]] != S[i]) X[i] = X[X[i]-1];
			if(S[X[i]] == S[i]) X[i]++;
		}
		
		long ans = N + (long)(K-1)*(N-X[N-1]);
		bw.write(ans + "\n");
		
	}
	
}