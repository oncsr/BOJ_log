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
	
	static int V, E;
	static List<Integer>[] G, R;
	static Stack<Integer> S;
	static boolean[] vis;
	static int ord = 0;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		V = nextInt();
		E = nextInt();
		G = new List[V+1];
		R = new List[V+1];
		S = new Stack<>();
		vis = new boolean[V+1];
		for(int i=1;i<=V;i++) {
			G[i] = new ArrayList<>();
			R[i] = new ArrayList<>();
		}
		for(int i=0;i<E;i++) {
			int a = nextInt(), b = nextInt();
			G[a].add(b);
			R[b].add(a);
		}
		
	}
	
	static void solve() throws Exception {
		
		for(int i=1;i<=V;i++) if(!vis[i]) {
			vis[i] = true;
			dfs1(i);
		}
		
		vis = new boolean[V+1];
		List<List<Integer>> ans = new ArrayList<>();
		while(!S.isEmpty()) {
			int n = S.pop();
			if(vis[n]) continue;
			vis[n] = true;
			List<Integer> res = new ArrayList<>();
			dfs2(n, res);
			Collections.sort(res);
			ans.add(res);
		}
		Collections.sort(ans, (a,b) -> a.get(0).compareTo(b.get(0)));
		
		bw.write(ans.size() + "\n");
		for(List<Integer> res:ans) {
			for(int i:res) bw.write(i + " ");
			bw.write("-1\n");
		}
		
	}
	
	static void dfs1(int n) {
		ord++;
		for(int i:G[n]) if(!vis[i]) {
			vis[i] = true;
			dfs1(i);
		}
		S.add(n);
	}
	
	static void dfs2(int n, List<Integer> L) {
		L.add(n);
		for(int i:R[n]) if(!vis[i]) {
			vis[i] = true;
			dfs2(i, L);
		}
	}
	
}