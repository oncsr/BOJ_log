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
	static int[][] cost;
	
	static int INF = 1234567;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		cost = new int[N+1][N+1];
		for(int i=1;i<=N;i++) Arrays.fill(cost[i], INF);
		
		for(int i=1;i<=M;i++) {
			int a = nextInt(), b = nextInt(), c = nextInt();
			cost[a][b] = Math.min(cost[a][b], c);
			cost[b][a] = Math.min(cost[b][a], c);
		}
		
	}
	
	static void solve() throws Exception{
		
		int[] D = new int[N+1];
		Arrays.fill(D, INF);
		int[] P = new int[N+1];
		PriorityQueue<int[]> Q = new PriorityQueue<>((a,b) -> a[0]-b[0]);
		
		D[1] = 0;
		Q.offer(new int[] {0,1});
		while(!Q.isEmpty()) {
			int[] now = Q.poll();
			int d = now[0], n = now[1];
			if(d > D[n]) continue;
			for(int i=1;i<=N;i++) if(D[i] > d+cost[n][i]) {
				D[i] = d+cost[n][i];
				P[i] = n;
				Q.offer(new int[] {D[i],i});
			}
		}
		
		bw.write((N-1) + "\n");
		for(int i=2;i<=N;i++) bw.write(i + " " + P[i] + "\n");
		
	}
	
}