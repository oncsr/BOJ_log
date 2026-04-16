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
	
	static int N, K;
	static List<Integer>[] V;
	static int[][] edges;
	static int[] par, dep, r, ans;
	
	static int f(int x) {return x==r[x] ? x : (r[x]=f(r[x]));}
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		K = nextInt();
		V = new List[N+1];
		r = new int[N+1];
		ans = new int[N+1];
		for(int i=1;i<=N;i++) {
			V[i] = new ArrayList<>();
			r[i] = i;
		}
		edges = new int[N-1][];
		for(int i=0;i<N-1;i++) {
			int a = nextInt(), b = nextInt();
			edges[i] = new int[] {a,b};
			V[a].add(b);
			V[b].add(a);
		}
		
		par = new int[N+1];
		dep = new int[N+1];
		
	}
	
	static void solve() throws Exception{
		
		dfs(1,0,0);
		int[][] E = new int[K][2];
		for(int i=K-1;i>=0;i--) E[i] = new int[] {nextInt(), nextInt()};
		int k = K;
		for(int[] e:E) {
			int a = e[0], b = e[1];
			while(f(a) != f(b)) {
				a = f(a);
				b = f(b);
				if(dep[a] < dep[b]) {
					a^=b;
					b^=a;
					a^=b;
				}
				ans[a] = k;
				r[a] = f(par[a]);
				a = r[a];
			}
			k--;
		}
		for(int i=0;i<N-1;i++) {
			int x = edges[i][0], y = edges[i][1];
			if(par[x] == y) bw.write(ans[x] + "\n");
			else bw.write(ans[y] + "\n");
		}
		
	}
	
	static void dfs(int n, int p, int d) {
		par[n] = p;
		dep[n] = d;
		for(int i:V[n]) if(i != p) dfs(i,n,d+1);
	}
	
}