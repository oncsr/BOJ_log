import java.util.*;
import java.io.*;

class Main {
	
	// IO field
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;

	static void nextLine() throws Exception {st = new StringTokenizer(br.readLine());}
	static int nextInt() {return Integer.parseInt(st.nextToken());}
	static long nextLong() {return Long.parseLong(st.nextToken());}
	static void bwEnd() throws Exception {bw.flush();bw.close();}
	
	// Additional field
	static int N;
	static int sz;
	static int[] dep;
	static int[][] par;
	static List<Integer>[] V;
	
	static void initialize() {
		
		V = new ArrayList[N+1];
		sz = (int)(Math.log10(N-1)/Math.log10(2)) + 1;
		dep = new int[N+1];
		for(int i=1;i<=N;i++) V[i] = new ArrayList<>();
		par = new int[N+1][sz];
		
	}
	
	static void input() throws Exception {
		
		N = Integer.parseInt(br.readLine());
		initialize();
		
		for(int i=1;i<N;i++) {
			nextLine();
			int a = nextInt(), b = nextInt();
			V[a].add(b);
			V[b].add(a);
		}
		
	}
	
	static void dfs(int n, int p, int d) {
		par[n][0] = p;
		dep[n] = d;
		for(int x : V[n]) {
			if(x == p) continue;
			dfs(x, n, d+1);
		}
	}
	
	static void constructSparseTable() {
		for(int k=1;k<sz;k++) {
			for(int i=1;i<=N;i++) {
				par[i][k] = par[par[i][k-1]][k-1];
			}
		}
	}
	
	static int lca(int u, int v) {
		while(dep[u] != dep[v]) {
			if(dep[u] > dep[v]) {
				int diff = dep[u] - dep[v];
				for(int i=0;i<sz;i++) if((diff & (1<<i)) != 0) u = par[u][i];
			}
			else {
				int diff = dep[v] - dep[u];
				for(int i=0;i<sz;i++) if((diff & (1<<i)) != 0) v = par[v][i];
			}
		}
		while(par[u][0] != par[v][0]) {
			for(int i=sz-1;i>=0;i--) {
				if(par[u][i] != par[v][i]) {
					u = par[u][i];
					v = par[v][i];
					break;
				}
			}
		}
		
		if(u != v) u = par[u][0];
		return u;
		
	}
	
	static void handleQuery() throws Exception {
		int Q = Integer.parseInt(br.readLine());
		while(Q-- > 0) {
			nextLine();
			int u = nextInt(), v = nextInt();
			bw.write(lca(u,v) + "\n");
		}
	}
	
	public static void main(String[] args) throws Exception {

		input();
		dfs(1,0,0);
		constructSparseTable();
		handleQuery();
		
		bwEnd();
	}

}