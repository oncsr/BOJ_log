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
	static List<Integer>[] G, R;
	static Stack<Integer> S;
	static int[] C, D;
	static boolean[] vis;
	
	public static void main(String[] args) throws Exception {
		
		for(int T=nextInt();T-->0;solve()) ready();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		G = new List[N+1];
		R = new List[N+1];
		for(int i=1;i<=N;i++) {
			G[i] = new ArrayList<>();
			R[i] = new ArrayList<>();
		}
		for(int i=0;i<M;i++) {
			int a = nextInt(), b = nextInt();
			G[a].add(b);
			R[b].add(a);
		}
		S = new Stack<>();
		C = new int[N+1];
		
	}
	
	static void solve() throws Exception {
		
		vis = new boolean[N+1];
		for(int i=1;i<=N;i++) if(!vis[i]) {
			vis[i] = true;
			dfs1(i);
		}
		
		vis = new boolean[N+1];
		int cnt = 0;
		while(!S.isEmpty()) {
			int n = S.pop();
			if(vis[n]) continue;
			vis[n] = true;
			dfs2(n,++cnt);
		}
		
		D = new int[cnt+1];
		for(int i=1;i<=N;i++) for(int j:G[i]) {
			if(C[i] != C[j]) D[C[j]]++;
		}
		
		int ans = 0;
		for(int i=1;i<=cnt;i++) if(D[i] == 0) ans++;
		bw.write(ans + "\n");
		
	}
	
	static void dfs1(int n) {
		for(int i:G[n]) if(!vis[i]) {
			vis[i] = true;
			dfs1(i);
		}
		S.add(n);
	}
	
	static void dfs2(int n, int c) {
		C[n] = c;
		for(int i:R[n]) if(!vis[i]) {
			vis[i] = true;
			dfs2(i,c);
		}
	}
	
}