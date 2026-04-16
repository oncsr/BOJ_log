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
	
	static int N, M, T;
	static int[][] dist;
	
	static final int INF = (int)1e9 + 7;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		T = nextInt();
		dist = new int[N+1][N+1];
		for(int i=1;i<=N;i++) Arrays.fill(dist[i], INF);
		for(int i=1;i<=M;i++) {
			int u = nextInt(), v = nextInt(), h = nextInt();
			dist[u][v] = Math.min(dist[u][v], h);
		}
		
	}
	
	static void solve() throws Exception{
		
		for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) for(int k=1;k<=N;k++) dist[j][k] = Math.min(dist[j][k], Math.max(dist[j][i], dist[i][k])); 
		while(T-->0) {
			int s = nextInt(), e = nextInt();
			bw.write((dist[s][e] == INF ? -1 : dist[s][e]) + "\n");
		}
		
	}
	
}