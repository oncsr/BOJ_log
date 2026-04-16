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
	static List<Integer>[] V;
	static int[] par, dep, r, ans;
	static int[][] edges, org;
	
	static int f(int x) {return x==r[x] ? x : (r[x]=f(r[x]));}
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		V = new List[N+1];
		par = new int[N+1];
		dep = new int[N+1];
		ans = new int[N+1];
		r = new int[N+1];
		org = new int[N][2];
		for(int i=1;i<=N;i++) {
			V[i] = new ArrayList<>();
			r[i] = i;
			ans[i] = -1;
		}
		for(int i=1;i<N;i++) {
			int a = nextInt(), b = nextInt();
			org[i][0] = a;
			org[i][1] = b;
			V[a].add(b);
			V[b].add(a);
		}
		edges = new int[M][3];
		for(int i=0;i<M;i++) for(int j=0;j<3;j++) edges[i][j] = nextInt();
		
	}
	
	static void solve() throws Exception {
		
		dfs(1,0,0);
		Arrays.sort(edges, (a,b) -> a[2]-b[2]);
		for(int[] e:edges) {
			int a = e[0], b = e[1], c = e[2];
			while(f(a) != f(b)) {
				a = f(a);
				b = f(b);
				if(dep[a] > dep[b]) {
					ans[a] = c;
					a = r[a] = f(par[a]);
				}
				else {
					ans[b] = c;
					b = r[b] = f(par[b]);
				}
			}
		}
		
		for(int i=1;i<N;i++) {
			int a = org[i][0], b = org[i][1];
			bw.write((par[a] == b ? ans[a] : ans[b]) + "\n");
		}
		
	}
	
	static void dfs(int n, int p, int d) {
		par[n] = p;
		dep[n] = d;
		for(int i:V[n]) if(i != p) dfs(i, n, d+1);
	}
	
}