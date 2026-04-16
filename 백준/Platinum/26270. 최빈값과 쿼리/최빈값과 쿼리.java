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
	
	static int N, K, Q;
	static List<Integer>[] I;
	static int[] R;
	static int[][] queries;
	
	static int[] seg;
	
	static final int INF = (int)1e9 + 7;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		K = nextInt();
		Q = nextInt();
		I = new List[N+1];
		for(int i=1;i<=N;i++) I[i] = new ArrayList<>();
		for(int i=1;i<=N;i++) I[nextInt()].add(i);
		R = new int[N+1];
		Arrays.fill(R, INF);
		
		queries = new int[Q][3];
		for(int i=0;i<Q;i++) queries[i] = new int[] {nextInt(), nextInt(), i};
		seg = new int[N*4];
		Arrays.fill(seg, INF);
		
	}
	
	static void solve() throws Exception{
		
		for(int i=1;i<=N;i++) {
			for(int j=0;j<I[i].size()-K+1;j++) {
				int st = I[i].get(j), ed = I[i].get(j+K-1);
				R[ed] = st;
			}
		}
		
		Arrays.sort(queries, (a,b) -> a[1]==b[1] ? a[0]-b[0] : a[1]-b[1]);
		int[] ans = new int[Q];
		int right = 0;
		for(int[] query:queries) {
			int l = query[0], r = query[1], i = query[2];
			
			while(right < r) {
				right++;
				if(R[right] != INF) upt(1,N,R[right],right-R[right]+1,1);
			}
			ans[i] = find(1,N,l,right,1);
			if(ans[i] == INF) ans[i] = -1;
			
		}
		for(int i:ans) bw.write(i + "\n");
		
	}
	
	static void upt(int s, int e, int i, int v, int n) {
		if(s == e) {
			seg[n] = v;
			return;
		}
		int m=(s+e)>>1;
		if(i <= m) upt(s,m,i,v,n*2);
		else upt(m+1,e,i,v,n*2+1);
		seg[n] = Math.min(seg[n*2], seg[n*2+1]);
	}
	
	static int find(int s, int e, int l, int r, int n) {
		if(l>r || l>e || r<s) return INF;
		if(l<=s && e<=r) return seg[n];
		int m=(s+e)>>1;
		return Math.min(find(s,m,l,r,n*2), find(m+1,e,l,r,n*2+1));
	}
	
}