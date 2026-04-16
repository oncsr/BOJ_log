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
	
	static int N, M, K;
	static long[] seg;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		K = nextInt();
		seg = new long[N*4];
		for(int i=1;i<=N;i++) upt(1,N,i,nextLong(),1);

	}
	
	static void solve() throws Exception{
		
		for(int i=0;i<M+K;i++) {
			long o = nextInt(), a = nextInt(), b = nextLong();
			if(o == 1) upt(1,N,(int)a,b,1);
			else bw.write(find(1,N,(int)a,(int)b,1) + "\n");
		}
		
	}
	
	static void upt(int s, int e, int i, long v, int n) {
		if(s == e) {
			seg[n] = v;
			return;
		}
		int m=(s+e)>>1;
		if(i<=m) upt(s,m,i,v,n*2);
		else upt(m+1,e,i,v,n*2+1);
		seg[n] = seg[n*2] + seg[n*2+1];
	}
	
	static long find(int s, int e, int l, int r, int n) {
		if(l>r || l>e || r<s) return 0;
		if(l<=s && e<=r) return seg[n];
		int m=(s+e)>>1;
		return find(s,m,l,r,n*2) + find(m+1,e,l,r,n*2+1);
	}
	
}