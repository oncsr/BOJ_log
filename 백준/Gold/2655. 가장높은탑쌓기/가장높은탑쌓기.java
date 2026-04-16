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
	
	static int N;
	static int[] height, weight, len, deg, dp, par;
	static boolean[][] V;
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		height = new int[N];
		weight = new int[N];
		len = new int[N];
		for(int i=0;i<N;i++) {
			len[i] = nextInt();
			height[i] = nextInt();
			weight[i] = nextInt();
		}
		
		deg = new int[N];
		V = new boolean[N][N];
		dp = new int[N];
		par = new int[N];
		Arrays.fill(par, -1);
		
	}
	
	static void solve() throws Exception{
		
		for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(i != j) {
			if(len[i] > len[j] && weight[i] > weight[j]) {
				V[i][j] = true;
				deg[j]++;
			}
		}
		
		Queue<Integer> Q = new LinkedList<>();
		for(int i=0;i<N;i++) if(deg[i] == 0) {
			Q.offer(i);
			dp[i] = height[i];
		}
		
		while(!Q.isEmpty()) {
			int now = Q.poll();
			
			for(int i=0;i<N;i++) if(V[now][i]) {
				if(dp[now] + height[i] > dp[i]) {
					dp[i] = dp[now] + height[i];
					par[i] = now;
				}
				if(--deg[i] == 0) Q.offer(i);
			}
			
		}
		
		int max = 0;
		for(int i=0;i<N;i++) max = Math.max(max, dp[i]);
		
		for(int i=0;i<N;i++) if(dp[i] == max) {
			
			Queue<Integer> S = new LinkedList<>();
			while(i != -1) {
				S.add(i);
				i = par[i];
			}
			
			bw.write(S.size() + "\n");
			while(!S.isEmpty()) bw.write((S.poll()+1) + "\n");
			
			break;
		}
		
	}
	
}