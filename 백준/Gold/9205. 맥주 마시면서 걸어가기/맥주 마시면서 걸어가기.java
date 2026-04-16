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
	static int[][] A;
	
	public static void main(String[] args) throws Exception {
		
		for(int T=nextInt();T-->0;solve()) ready();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt() + 2;
		A = new int[N][2];
		for(int i=0;i<N;i++) for(int j=0;j<2;j++) A[i][j] = nextInt();
		
	}
	
	static void solve() throws Exception{
		
		boolean[][] V = new boolean[N][N];
		
		for(int i=0;i<N;i++) for(int j=0;j<i;j++) {
			int dist = Math.abs(A[i][0]-A[j][0]) + Math.abs(A[i][1]-A[j][1]);
			if(dist <= 1000) V[i][j] = V[j][i] = true;
		}
		
		
		Queue<Integer> Q = new LinkedList<>();
		boolean[] vis = new boolean[N];
		vis[0] = true;
		Q.offer(0);
		while(!Q.isEmpty()) {
			int n = Q.poll();
			if(n == N-1) {
				bw.write("happy\n");
				return;
			}
			for(int i=0;i<N;i++) if(V[n][i] && !vis[i]) {
				vis[i] = true;
				Q.offer(i);
			}
		}
		bw.write("sad\n");
	}
	
}