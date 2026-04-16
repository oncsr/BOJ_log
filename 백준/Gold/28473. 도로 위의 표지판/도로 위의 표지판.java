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
	static int[][] E;
	static int[] r;

	static int f(int x) {return x==r[x] ? x : (r[x]=f(r[x]));}
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		r = new int[N+1];
		for(int i=1;i<=N;i++) r[i] = i;
		E = new int[M][];
		for(int i=0;i<M;i++) E[i] = new int[] {nextInt(), nextInt(), nextInt(), nextInt()};

	}
	
	static void solve() throws Exception{
		
		Arrays.sort(E, (a,b) -> a[2]==b[2] ? a[3]-b[3] : a[2]-b[2]);
		int[] C = new int[10];
		int cnt = 0;
		long mst = 0;
		for(int[] e:E) {
			int a = e[0], b = e[1], c = e[2], d = e[3];
			int x = f(a), y = f(b);
			if(x == y) continue;
			C[c]++;
			mst += d;
			cnt++;
			r[x] = y;
		}
		if(cnt != N-1) bw.write("-1");
		else {
			for(int i=1;i<10;i++) {
				for(int j=0;j<C[i];j++) bw.write(i+"");
			}
			bw.write(" " + mst);
		}
		
	}
	
}