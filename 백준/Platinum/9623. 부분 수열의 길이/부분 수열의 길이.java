import java.awt.image.AreaAveragingScaleFilter;
import java.util.*;
import java.io.*;

class IOController {
	BufferedReader br;
	BufferedWriter bw;
	StringTokenizer st;

	public IOController() {
		br = new BufferedReader(new InputStreamReader(System.in));
		bw = new BufferedWriter(new OutputStreamWriter(System.out));
		st = new StringTokenizer("");
	}

	String nextLine() throws Exception {
		String line = br.readLine();
		st = new StringTokenizer(line);
		return line;
	}

	String nextToken() throws Exception {
		while (!st.hasMoreTokens()) nextLine();
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

	void close() throws Exception {
		bw.flush();
		bw.close();
	}

	void write(String content) throws Exception {
		bw.write(content);
	}

}

public class Main {

	static IOController io;

	//

	static int N;
	static long X;
	static long[] a, seg;

	public static void main(String[] args) throws Exception {

		io = new IOController();

		for(int T=io.nextInt();T-->0;) {
			init();
			solve();
		}

		io.close();

	}

	static void init() throws Exception {

		N = io.nextInt();
		X = io.nextLong();
		a = new long[N+1];
		seg = new long[N*4];
		for(int i=1;i<=N;i++) a[i] = a[i-1] + io.nextInt();

	}

	static void solve() throws Exception {

		pre(1,N,1);
		int ans = N+1;
		for(int i=1;i<=N;i++) {
			int e = find(1,N,X+a[i-1],1);
			if(e != N+1) ans = Math.min(ans, e-i+1);
			upt(1,N,i,1);
		}
		io.write((ans == N+1 ? -1 : ans) + "\n");

	}

	static long pre(int s, int e, int n) {
		if(s == e) return seg[n] = a[s];
		int m = (s+e)>>1;
		return seg[n] = Math.max(pre(s,m,n*2), pre(m+1,e,n*2+1));
	}

	static int find(int s, int e, long v, int n) {
		 if(s == e) return s;
		 int m = (s+e)>>1;
		 if(seg[n*2] >= v) return find(s,m,v,n*2);
		 else if(seg[n*2+1] >= v) return find(m+1,e,v,n*2+1);
		 return N+1;
	}

	static void upt(int s, int e, int i, int n) {
		if(s == e) {
			seg[n] = -(long)1e18 - 7;
			return;
		}
		int m = (s+e)>>1;
		if(i <= m) upt(s,m,i,n*2);
		else upt(m+1,e,i,n*2+1);
		seg[n] = Math.max(seg[n*2], seg[n*2+1]);
	}

}