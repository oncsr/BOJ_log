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
	static int[][] E;
	static List<int[]>[] V;
	static int[] r;
	static int mst = 0, dist = 0;
	
	static int f(int x) {return x==r[x] ? x : (r[x]=f(r[x]));}
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		K = nextInt();
		E = new int[K][3];
		for(int i=0;i<K;i++) E[i] = new int[] {nextInt(), nextInt(), nextInt()};
		V = new List[N];
		r = new int[N];
		for(int i=0;i<N;i++) {
			V[i] = new ArrayList<>();
			r[i] = i;
		}
		
	}
	
	static void solve() throws Exception{
		
		Arrays.sort(E, (a,b) -> a[2]-b[2]);
		for(int[] e:E) {
			int a = e[0], b = e[1], c = e[2];
			int x = f(a), y = f(b);
			if(x==y) continue;
			mst += c;
			r[x] = y;
			V[a].add(new int[] {b,c});
			V[b].add(new int[] {a,c});
		}
		dfs(0,-1);
		bw.write(mst + "\n" + dist);
		
	}
	
	static int dfs(int n, int p) {
		int mx1 = 0, mx2 = 0;
		for(int[] next:V[n]) if(next[0] != p) {
			int res = dfs(next[0],n) + next[1];
			if(res > mx1) {
				mx2 = mx1;
				mx1 = res;
			}
			else if(res > mx2) mx2 = res;
		}
		dist = Math.max(dist, mx1 + mx2);
		return mx1;
	}
	
}