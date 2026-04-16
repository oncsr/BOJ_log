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
	
	static int K, N;
	static int[] A, B, C;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		K = nextInt();
		A = new int[N];
		B = new int[N];
		C = new int[N];
		for(int i=0;i<N;i++) {
			A[i] = nextInt();
			B[i] = nextInt();
			C[i] = nextInt();
		}
		
	}
	
	static void solve() throws Exception{
		
		int ans = Integer.MAX_VALUE;
		for(int a=0;a<N;a++) for(int b=0;b<N;b++) for(int c=0;c<N;c++) {
			int cnt = 0;
			for(int i=0;i<N;i++) {
				if(A[a] >= A[i] && B[b] >= B[i] && C[c] >= C[i]) cnt++;
			}
			if(cnt >= K) ans = Math.min(ans, A[a] + B[b] + C[c]);
		}
		bw.write(ans + "\n");
		
	}
	
}