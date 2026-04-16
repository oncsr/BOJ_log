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
	
	static int N, M;
	static char[] T, P;
	static int[] X;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		T = br.readLine().toCharArray();
		P = new char[2*N+1];
		P[0] = 'I';
		for(int i=1;i<=N;i++) {
			P[i*2-1] = 'O';
			P[i*2] = 'I';
		}
		X = new int[2*N+1];

	}
	
	static void solve() throws Exception{
		
		for(int i=1;i<2*N+1;i++) {
			X[i] = X[i-1];
			while(X[i]>0 && P[X[i]] != P[i]) X[i] = X[X[i]-1];
			if(P[X[i]] == P[i]) X[i]++;
		}
		
		int ans = 0;
		for(int i=0,j=0;i<M;i++) {
			while(j>0 && P[j] != T[i]) j = X[j-1];
			if(P[j] == T[i]) j++;
			if(j == 2*N+1) {
				ans++;
				j = X[j-1];
			}
		}
		bw.write(ans + "\n");
		
	}
	
}