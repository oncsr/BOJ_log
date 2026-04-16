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
	static char[] P, T;
	static int[] X;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		P = new char[N];
		T = new char[N];
		for(int i=0;i<N;i++) P[i] = nextToken().charAt(0);
		for(int i=0;i<N;i++) T[i] = nextToken().charAt(0);
		X = new int[N];
		
	}
	
	static void solve() throws Exception{
		
		for(int i=1;i<N;i++) {
			X[i] = X[i-1];
			while(X[i]>0 && P[X[i]] != P[i]) X[i] = X[X[i]-1];
			if(P[X[i]] == P[i]) X[i]++;
		}
		
		int cnt = 0;
		for(int i=0,j=0;i<2*N-1;i++) {
			while(j>0 && P[j] != T[i%N]) j = X[j-1];
			if(P[j] == T[i%N]) j++;
			if(j == N) {
				cnt++;
				j = X[j-1];
			}
		}
		
		if(cnt == N) bw.write("1/1");
		else {
			for(int i=2;i<=N;i++) while(cnt%i==0 && N%i==0) {
				cnt/=i;
				N/=i;
			}
			bw.write(cnt + "/" + N);
		}
		
	}
	
}