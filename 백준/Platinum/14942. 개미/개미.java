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
	static List<int[]>[] V;
	
	static int[][] par, dist;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		A = new int[N+1];
		V = new List[N+1];
		for(int i=1;i<=N;i++) V[i] = new ArrayList<>();
		for(int i=1;i<=N;i++) A[i] = nextInt();
		for(int i=1;i<N;i++) {
			int a = nextInt(), b = nextInt(), c = nextInt();
			V[a].add(new int[] {b,c});
			V[b].add(new int[] {a,c});
		}
		par = new int[N+1][17];
		dist = new int[N+1][17];

	}
	
	static void solve() throws Exception{
		
		dfs(1,0);
		constructSparseTable();
		for(int i=1;i<=N;i++) bw.write(find(i) + "\n");
		
	}
	
	static void dfs(int n, int p) {
		par[n][0] = p;
		for(int[] next:V[n]) if(next[0] != p) {
			int i = next[0], c = next[1];
			dist[i][0] = c;
			dfs(i,n);
		}
	}
	
	static void constructSparseTable() {
		
		for(int k=1;k<17;k++) for(int i=1;i<=N;i++) {
			par[i][k] = par[par[i][k-1]][k-1];
			dist[i][k] = dist[i][k-1] + dist[par[i][k-1]][k-1];
		}
		
	}
	
	static int find(int x) {
		
		int val = A[x];
		for(int k=16;k>=0;k--) {
			if(val >= dist[x][k]) {
				val -= dist[x][k];
				x = par[x][k];
			}
		}
		return x==0 ? 1 : x;
		
	}
	
}