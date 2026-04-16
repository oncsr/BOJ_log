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
	
	static int N, M;
	static List<int[]> E;
	static List<int[]>[] V;
	static int[][] max, par;
	static int[] r, dep;
	
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
		V = new List[N+1];
		r = new int[N+1];
		dep = new int[N+1];
		max = new int[N+1][17];
		par = new int[N+1][17];
		for(int i=1;i<=N;i++) {
			r[i] = i;
			V[i] = new ArrayList<>();
		}
		for(int i=0;i<M;i++) E.add(new int[] {nextInt(), nextInt(), nextInt(), 0});
		
	}
	
	static void solve() throws Exception {
		
		Collections.sort(E, (a,b) -> a[2]-b[2]);
		for(int[] e:E) {
			int a = e[0], b = e[1], c = e[2];
			int x = f(a), y = f(b);
			if(x == y) continue;
			r[x] = y;
			e[3] = 1;
		}
		
		for(int i=1;i<=N;i++) r[i] = i;
		int C = 0;
		for(int[] e:E) if(e[3] != 1) {
			int a = e[0], b = e[1], c = e[2];
			int x = f(a), y = f(b);
			if(x == y) continue;
			r[x] = y;
			V[a].add(new int[] {b,c});
			V[b].add(new int[] {a,c});
			C++;
		}
		if(C != N-1) {
			bw.write("-1");
			return;
		}
		
		dfs(1,0,0);
		spt();
		
		long ans = 0;
		for(int[] e:E) if(e[3] == 1) {
			int a = e[0], b = e[1], c = e[2];
			int x = findmax(a,b);
			ans += x+1-c; 
		}
		bw.write(ans + "\n");
		
	}
	
	static void dfs(int n, int p, int d) {
		par[n][0] = p;
		dep[n] = d;
		for(int[] e:V[n]) if(e[0] != p) {
			dfs(e[0], n, d+1);
			max[e[0]][0] = e[1];
		}
	}
	
	static void spt() {
		for(int k=1;k<17;k++) for(int i=1;i<=N;i++) {
			par[i][k] = par[par[i][k-1]][k-1];
			max[i][k] = Math.max(max[i][k-1], max[par[i][k-1]][k-1]);
		}
	}
	
	static int findmax(int a, int b) {
		int res = 0;
		int diff = Math.abs(dep[a]-dep[b]);
		for(int k=0;k<17;k++) if((diff & (1<<k)) != 0) {
			if(dep[a] > dep[b]) {
				res = Math.max(res, max[a][k]);
				a = par[a][k];
			}
			else {
				res = Math.max(res, max[b][k]);
				b = par[b][k];
			}
		}
		
		for(int k=16;k>=0;k--) {
			if(par[a][k] != par[b][k]) {
				res = Math.max(res, Math.max(max[a][k], max[b][k]));
				a = par[a][k];
				b = par[b][k];
			}
		}
		
		if(a != b) {
			res = Math.max(res, Math.max(max[a][0], max[b][0]));
		}
		return res;
	}
	
}