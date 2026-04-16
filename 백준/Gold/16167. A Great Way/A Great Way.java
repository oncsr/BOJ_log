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
	
	static int N, R;
	static int[][] C;
	
	static final int INF = 12345678;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		R = nextInt();
		C = new int[N+1][N+1];
		for(int i=1;i<=N;i++) Arrays.fill(C[i], INF);
		for(int i=0;i<R;i++) {
			int a = nextInt(), b = nextInt(), c = nextInt(), d = nextInt(), e = nextInt();
			int cost = c + (e > 10 ? d*(e-10) : 0);
			C[a][b] = Math.min(C[a][b], cost);
		}
		
	}
	
	static void solve() throws Exception{
		
		PriorityQueue<int[]> Q = new PriorityQueue<>((a,b) -> {
			return a[0]-b[0];
		});
		int[] D = new int[N+1];
		int[] S = new int[N+1];
		Arrays.fill(D, INF);
		Arrays.fill(S, INF);
		
		D[1] = 0;
		S[1] = 1;
		Q.offer(new int[] {0,1});
		while(!Q.isEmpty()) {
			int[] now = Q.poll();
			int d = now[0], n = now[1];
			if(d > D[n]) continue;
			for(int i=1;i<=N;i++) if(C[n][i] != INF) {
				if(D[i] > d+C[n][i]) {
					D[i] = d+C[n][i];
					S[i] = S[n]+1;
					Q.offer(new int[] {D[i],i});
				}
				else if(D[i] == d+C[n][i] && S[i] > S[n]+1) {
					S[i] = S[n]+1;
				}
			}
		}
		if(D[N] == INF) bw.write("It is not a great way.");
		else bw.write(D[N] + " " + S[N]);
		
	}
	
}