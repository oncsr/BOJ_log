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
	
	static int N, C, M;
	static int[] S, E;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		C = nextInt();
		M = nextInt();
		S = new int[N+1];
		E = new int[N+1];
		for(int i=0;i<M;i++) {
			int s = nextInt(), e = nextInt(), v = nextInt();
			S[s] += v;
			E[e] += v;
		}
		
	}
	
	static void solve() throws Exception {
		
		int ans = 0, cur = 0;
		for(int i=1;i<=N;i++) {
			int diff = Math.min(E[i], cur);
			cur -= diff;
			ans += diff;
			cur = Math.min(cur + S[i], C);
		}
		bw.write(ans + "\n");
		
	}
	
}