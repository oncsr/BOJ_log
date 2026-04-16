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
	
	static int N, M, R;
	static int[] A, B;
	static List<Integer>[] V;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		R = nextInt();
		A = new int[N+1];
		B = new int[N+1];
		V = new List[N+1];
		for(int i=1;i<=N;i++) A[i] = nextInt();
		for(int i=1;i<=N;i++) B[i] = nextInt();
		for(int i=1;i<=N;i++) V[i] = new ArrayList<>();
		for(int i=0;i<M;i++) {
			int a = nextInt(), b = nextInt();
			V[a].add(b);
			V[b].add(a);
		}

	}
	
	static void solve() throws Exception{
		
		long ans = 0;
		boolean[] vis = new boolean[N+1];
		PriorityQueue<int[]> Q = new PriorityQueue<>((a,b) -> a[1]-b[1]);
		Q.offer(new int[] {R, A[R], B[R]});
		while(!Q.isEmpty()) {
			int[] now = Q.poll();
			int n = now[0], a = now[1], b = now[2];
			if(vis[n]) continue;
			vis[n] = true;
			if(a <= ans) ans += b;
			else break;
			for(int i:V[n]) if(!vis[i]) Q.offer(new int[] {i, A[i], B[i]});
		}
		bw.write(ans + "\n");
		
	}
	
}