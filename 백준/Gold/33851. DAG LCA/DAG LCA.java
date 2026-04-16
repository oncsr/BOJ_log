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
	
	static int N, M, Q;
	static List<Integer>[] V;
	static int[][] D;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		Q = nextInt();
		V = new List[N+1];
		D = new int[N+1][N+1];
		for(int i=1;i<=N;i++) Arrays.fill(D[i], -1);
		for(int i=1;i<=N;i++) V[i] = new ArrayList<>();
		for(int i=0;i<M;i++) V[nextInt()].add(nextInt());
		
	}
	
	static void solve() throws Exception {
		
		for(int i=1;i<=N;i++) {
			Queue<int[]> Q = new LinkedList<>();
			boolean[] vis = new boolean[N+1];
			vis[i] = true;
			Q.offer(new int[] {i,0});
			while(!Q.isEmpty()) {
				int[] now = Q.poll();
				int n = now[0], t = now[1];
				D[i][n] = t;
				for(int j:V[n]) if(!vis[j]) {
					vis[j] = true;
					Q.offer(new int[] {j,t+1});
				}
			}
		}
		
		while(Q-->0) {
			int a = nextInt(), b = nextInt();
			int res = -1;
			for(int i=1;i<=N;i++) if(D[i][a] != -1 && D[i][b] != -1) {
				if(res == -1) res = 1000000;
				res = Math.min(res, Math.max(D[i][a], D[i][b]));
			}
			bw.write(res + "\n");
		}
		
	}
	
}