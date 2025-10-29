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
		G = new List[N];
		R = new List[N];
		for(int i=0;i<N;i++) {
			G[i] = new ArrayList<>();
			R[i] = new ArrayList<>();
		}
		for(int i=0;i<M;i++) {
			int a = nextInt(), b = nextInt();
			G[a].add(b);
			R[b].add(a);
		}
		S = new Stack<>();
		C = new int[N];
		
	}
	
	static void solve() throws Exception {
		
		vis = new boolean[N];
		for(int i=0;i<N;i++) if(!vis[i]) {
			vis[i] = true;
			dfs(i,-1);
		}
		
		vis = new boolean[N];
		int cnt = 0;
		while(!S.isEmpty()) {
			int n = S.pop();
			if(vis[n]) continue;
			vis[n] = true;
			dfs(n,++cnt);
		}
		
		D = new int[cnt+1];
		for(int i=0;i<N;i++) for(int j:G[i]) if(C[i] != C[j]) D[C[j]]++;
		
		int poss = 0, val = -1;
		for(int i=1;i<=cnt;i++) if(D[i] == 0) {
			if(poss != 0) {
				bw.write("Confused\n\n");
				return;
			}
			poss++;
			val = i;
		}
		for(int i=0;i<N;i++) if(C[i] == val) bw.write(i + "\n");
		bw.write("\n");
		
	}
	
	static void dfs(int n, int c) {
		for(int i:(c == -1 ? G[n] : R[n])) if(!vis[i]) {
			vis[i] = true;
			dfs(i, c);
		}
		if(c == -1) S.add(n);
		else C[n] = c;
	}
	
}