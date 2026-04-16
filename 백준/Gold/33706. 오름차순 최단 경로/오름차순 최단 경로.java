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
	
	static int N, M;
	static List<Integer>[] V;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		V = new List[N+1];
		for(int i=1;i<=N;i++) V[i] = new ArrayList<>();
		while(M-->0) {
			int a = nextInt(), b = nextInt();
			V[a].add(b);
			V[b].add(a);
		}
	}
	
	static void solve() throws Exception{
		
		PriorityQueue<Integer> Q = new PriorityQueue<>((a,b) -> a-b);
		boolean[] vis = new boolean[N+1];
		vis[1] = true;
		Q.offer(1);
		int mex = 1;
		while(!Q.isEmpty()) {
			int n = Q.poll();
			if(n != mex++) {
				bw.write("NO");
				return;
			}
			for(int i:V[n]) if(!vis[i]) {
				vis[i] = true;
				Q.offer(i);
			}
		}
		bw.write("YES");
		
	}
	
}