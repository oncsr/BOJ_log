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
	static int[] A;
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		A = new int[N];
		char[] temp = br.readLine().toCharArray();
		for(int i=0;i<N;i++) A[i] = temp[i]-'0';

	}
	
	static void solve() throws Exception{
		
		int idx = 0;
		while(idx < N && M > 0) {
			if(A[idx] != 0 && M >= 10-A[idx]) {
				M -= 10 - A[idx];
				A[idx] = 0;
			}
			idx++;
		}
		if(M > 0) {
			M %= 10;
			A[N-1] = (A[N-1] + M) % 10;
		}
		for(int i=0;i<N;i++) bw.write(A[i] + "");
		
	}
	
}