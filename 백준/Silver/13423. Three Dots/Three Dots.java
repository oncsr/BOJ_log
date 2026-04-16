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
	static int[] A;
	static TreeSet<Integer> S;
	
	public static void main(String[] args) throws Exception {
		
		for(int T=nextInt();T-->0;) {
			
			ready();
			solve();
		}
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		S = new TreeSet<>();
		A = new int[N];
		for(int i=0;i<N;i++) {
			A[i] = nextInt();
			S.add(A[i]);
		}
		
	}
	
	static void solve() throws Exception{
		
		Arrays.sort(A);
		int ans = 0;
		for(int i=0;i<N;i++) for(int j=i+1;j<N;j++) ans += S.contains(A[j] + A[j]-A[i]) ? 1 : 0;
		bw.write(ans + "\n");
		
	}
	
}