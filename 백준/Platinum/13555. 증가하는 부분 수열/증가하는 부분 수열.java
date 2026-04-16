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
	
	static int N, K;
	static int[][] seg;
	static int[][] D;
	static final int mod = 5000000;
	
	static List<int[]> L = new ArrayList<>();
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		K = nextInt();
		seg = new int[262145][K+1];
		
		
		for(int i=1;i<=N;i++) L.add(new int[] {nextInt(), i});
		Collections.sort(L, (a,b) -> {
			if(a[0] == b[0]) return b[1]-a[1];
			return a[0]-b[0];
		});
		
	}
	
	static void solve() throws Exception{

		for(int[] now : L) {
			int v = now[0], x = now[1];
			for(int i=K;i>1;i--) upt(1,N,x,find(1,N,1,x,1,i-1),1,i);
			upt(1,N,x,1,1,1);
		}
		int ans = seg[1][K];
		bw.write(ans + "\n");
		
	}
	
	static int find(int s, int e, int l, int r, int n, int k) {
		if(l>r || l>e || r<s) return 0;
		if(l<=s && e<=r) return seg[n][k];
		int m=(s+e)>>1;
		return (find(s,m,l,r,n*2,k) + find(m+1,e,l,r,n*2+1,k)) % mod;
	}
	
	static void upt(int s, int e, int i, int v, int n, int k) {
		if(s==e) {
			seg[n][k] = v;
			return;
		}
		int m=(s+e)>>1;
		if(i <= m) upt(s,m,i,v,n*2,k);
		else upt(m+1,e,i,v,n*2+1,k);
		seg[n][k] = (seg[n*2][k] + seg[n*2+1][k]) % mod;
	}
	
}