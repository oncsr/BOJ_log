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
	
	static final int INF = (int)1e9 + 7;
	
	static int N, M, Q;
	static int[] r;
	static int[][] E;
	static int[][] Queries;
	static List<Integer>[] V;
	static int[] dep;
	static int[][] max, par;
	
	static int f(int x) {return x==r[x] ? x : (r[x]=f(r[x]));}
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		
		E = new int[M][];
		for(int i=1;i<=M;i++) E[i-1] = new int[] {nextInt(), nextInt(), i};
		
		Q = nextInt();
		Queries = new int[Q][2];
		for(int i=0;i<Q;i++) for(int j=0;j<2;j++) Queries[i][j] = nextInt();
		
		r = new int[N+1];
		V = new List[N+1];
		for(int i=1;i<=N;i++) {
			r[i] = i;
			V[i] = new ArrayList<>();
		}
		dep = new int[N+1];
		par = new int[N+1][19];
		max = new int[N+1][19];
		
	}
	
	static void solve() throws Exception {
		
		Queue<int[]> U = new LinkedList<>();
		for(int[] e:E) {
			int a = e[0], b = e[1], c = e[2];
			int x = f(a), y = f(b);
			if(x == y) {
				U.add(e);
				continue;
			}
			r[x] = y;
			V[a].add(b);
			V[b].add(a);
		}
		
		int[] rcopy = new int[N+1];
		for(int i=1;i<=N;i++) rcopy[i] = f(i);
		
		dfs(1,0,0);
		for(int i=1;i<=N;i++) r[i] = i;
		while(!U.isEmpty()) {
			int[] e = U.poll();
			int a = e[0], b = e[1], c = e[2];
			a = f(a);
			b = f(b);
			while(a != b) {
				if(dep[a] > dep[b]) {
					max[a][0] = c;
					int p = f(par[a][0]);
					r[a] = p;
					a = p;
				}
				else {
					max[b][0] = c;
					int p = f(par[b][0]);
					r[b] = p;
					b = p;
				}
			}
		}
		
		for(int i=1;i<=N;i++) if(max[i][0] == 0) max[i][0] = INF;
		spt();
		for(int[] query:Queries) {
			int a = query[0], b = query[1];
			if(rcopy[a] != rcopy[b]) {
				bw.write("-1\n");
				continue;
			}
			
			int diff = Math.abs(dep[a]-dep[b]);
			int res = 0;
			for(int k=0;k<19;k++) if((diff & (1<<k)) != 0) {
				if(dep[a] > dep[b]) {
					res = Math.max(res, max[a][k]);
					a = par[a][k];
				}
				else {
					res = Math.max(res, max[b][k]);
					b = par[b][k];
				}
			}
			
			for(int k=18;k>=0;k--) {
				if(par[a][k] != par[b][k]) {
					res = Math.max(res, Math.max(max[a][k], max[b][k]));
					a = par[a][k];
					b = par[b][k];
				}
			}
			if(a != b) {
				res = Math.max(res, Math.max(max[a][0], max[b][0]));
			}
			
			if(res == INF) bw.write("-1\n");
			else bw.write(res + "\n");
		}
		
	}
	
	static void dfs(int n, int p, int d) {
		dep[n] = d;
		par[n][0] = p;
		for(int i:V[n]) if(i != p) dfs(i,n,d+1);
	}
	
	static void spt() {
		for(int k=1;k<19;k++) for(int i=1;i<=N;i++) {
			par[i][k] = par[par[i][k-1]][k-1];
			max[i][k] = Math.max(max[i][k-1], max[par[i][k-1]][k-1]);
		}
	}
	
}