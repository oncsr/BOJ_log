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
	
	static int N, K, T;
	static long[] A;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		K = nextInt();
		T = nextInt();
		A = new long[N];
		for(int i=0;i<N;i++) A[i] = nextInt();
		
	}
	
	static void solve() throws Exception {
		
		PriorityQueue<Long> Q = new PriorityQueue<>((a,b) -> Long.compare(b, a));
		Arrays.sort(A);
		long ans = T;
		int id = 0;
		while(K-->0) {
			while(id<N && A[id]<ans) Q.offer(A[id++]);
			if(!Q.isEmpty()) ans += Q.poll();
		}
		bw.write(ans + "\n");
		
	}
	
}