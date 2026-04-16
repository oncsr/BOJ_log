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
	static int[] A;
	static List<Integer>[] V;
	static long ans = 0;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		A = new int[N+1];
		char[] temp = br.readLine().toCharArray();
		for(int i=1;i<=N;i++) A[i] = temp[i-1] - '0';
		V = new List[N+1];
		for(int i=1;i<=N;i++) V[i] = new ArrayList<>();
		for(int i=1;i<N;i++) {
			int a = nextInt(), b = nextInt();
			V[a].add(b);
			V[b].add(a);
		}
		
	}
	
	static void solve() throws Exception{
		
		dfs(1,0);
		bw.write(ans + "\n");
		
	}
	
	static long dfs(int n, int p) {
		long res = 0;
		for(int i:V[n]) if(i != p) {
			long g = dfs(i,n);
			if(A[n] == 0) ans -= g*g;
			res += g;
		}
		if(A[n] == 0) ans += res*res;
		else ans += res*2;
		return A[n] == 1 ? 1 : res;
	}
	
}