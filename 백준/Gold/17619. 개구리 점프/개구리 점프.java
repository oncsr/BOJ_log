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
	
	static int N, Q;
	static int[][] A;
	
	static int[] r;
	
	static int f(int x) {return x==r[x] ? x : (r[x]=f(r[x]));}
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		Q = nextInt();
		A = new int[N][3];
		r = new int[N+1];
		for(int i=1;i<=N;i++) {
			r[i] = i;
			A[i-1] = new int[] {nextInt(), nextInt(), i};
			nextInt();
		}
		
	}
	
	static void solve() throws Exception{
		
		Arrays.sort(A, (a,b) -> a[0]==b[0] ? a[1]-b[1] : a[0]-b[0]);
		int rMax = -1, idx = -1;
		for(int i=1;i<N;i++) {
			if(A[i-1][1] >= rMax) {
				rMax = A[i-1][1];
				idx = A[i-1][2];
			}
			if(A[i][0] > rMax) continue;
			int x = f(A[i][2]), y = f(idx);
			if(x != y) r[x] = y;
		}
		
		for(int i=0;i<Q;i++) bw.write(f(nextInt()) == f(nextInt()) ? "1\n" : "0\n");
		
	}
	
}