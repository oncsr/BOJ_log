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
	
	static int N, M, Q;
	static List<int[]> E, S;
	static int[] c, r, w, dep;
	
	static List<int[]>[] V;
	static int[][] max, par;
	static boolean[] vis;
	
	static int f(int x) {return x==r[x] ? x : (r[x]=f(r[x]));}
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		E = new ArrayList<>();
		for(int i=0;i<M;i++) E.add(new int[] {nextInt(),nextInt(),nextInt()});
		Q = nextInt();
		S = new ArrayList<>();
		for(int i=0;i<Q;i++) S.add(new int[] {nextInt(),nextInt()});
		
		r = new int[N+1];
		c = new int[N+1];
		V = new List[N+1];
		dep = new int[N+1];
		max = new int[N+1][17];
		par = new int[N+1][17];
		for(int i=1;i<=N;i++) {
			r[i] = i;
			c[i] = 1;
			V[i] = new ArrayList<>();
		}
		
		w = new int[1000001];
		
	}
	
	static void solve() throws Exception {
		
		Collections.sort(E, (a,b) -> a[2]-b[2]);
		for(int[] e : E) {
			int a = e[0], b = e[1], t = e[2];
			int x = f(a), y = f(b);
			if(x == y) continue;
			c[y] += c[x];
			r[x] = y;
			w[t] = c[y];
			V[a].add(new int[] {b,t});
			V[b].add(new int[] {a,t});
		}
		
		vis = new boolean[N+1];
		for(int i=1;i<=N;i++) if(!vis[i]) {
			vis[i] = true;
			dfs(i, 0);
		}
		
		spt();
		
		for(int[] q:S) {
			int a = q[0], b = q[1];
			
			if(f(a) != f(b)) {
				bw.write("-1\n");
				continue;
			}
			
			int min = 0;
			int diff = Math.abs(dep[a]-dep[b]);
			for(int k=16;diff>0;k--) if(((1<<k) & diff) != 0) {
				diff -= (1<<k);
				if(dep[a] > dep[b]) {
					min = Math.max(min, max[a][k]);
					a = par[a][k];
				}
				else {
					min = Math.max(min, max[b][k]);
					b = par[b][k];
				}
			}
			
			while(par[a][0] != par[b][0]) {
				for(int k=16;k>=0;k--) if(par[a][k] != par[b][k]) {
					min = Math.max(min, Math.max(max[a][k], max[b][k]));
					a = par[a][k];
					b = par[b][k];
				}
			}
			
			if(a != b) {
				min = Math.max(min, Math.max(max[a][0], max[b][0]));
			}
			
			bw.write(min + " " + w[min] + "\n");
			
		}
		
	}
	
	static void dfs(int n, int d) {
		dep[n] = d;
		for(int[] e:V[n]) if(!vis[e[0]]) {
			par[e[0]][0] = n;
			max[e[0]][0] = e[1];
			vis[e[0]] = true;
			dfs(e[0], d+1);
		}
	}
	
	static void spt() {
		for(int k=1;k<17;k++) for(int i=1;i<=N;i++) {
			par[i][k] = par[par[i][k-1]][k-1];
			max[i][k] = Math.max(max[i][k-1], max[par[i][k-1]][k-1]);
		}
	}
	
}