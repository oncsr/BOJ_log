import java.io.*;
import java.util.*;

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
		while (!st.hasMoreTokens())
			nextLine();
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

class Node {
	long sum;
	int max;
	Node(long sum, int max) {
		this.sum = sum;
		this.max = max;
	}
}

public class Main {

	static IOController io;

	//

	static int N, Q;
	static int[] f, g, sieve;
	static Node[] seg;

	public static void main(String[] args) throws Exception {

		io = new IOController();

		preprocess(1_000_000);

		N = io.nextInt();
		Q = io.nextInt();
		seg = new Node[N*4];
		Arrays.fill(seg, new Node(0,0));
		for(int i=1;i<=N;i++) {
			int a = io.nextInt();
			pointUpdate(1,N,i,new Node(a, g[a]),1);
		}

		while(Q-->0) {
			int o = io.nextInt();
			int s = io.nextInt();
			int e = io.nextInt();
			if(o == 1) rangeUpdate(1,N,s,e,1);
			else io.write(find(1,N,s,e,1).sum + "\n");
		}

		io.close();

	}

	private static void preprocess(int limit) {
		sieve = new int[limit+1];
		for(int i=2;i*i<=limit;i++) if(sieve[i] == 0) for(int j=i*i;j<=limit;j+=i) if(sieve[j] == 0) sieve[j] = i;

		f = new int[limit+1];
		g = new int[limit+1];
		f[1] = 1;
		f[2] = 2;
		for(int i=3;i<=limit;i++) {
			int t = i, prev = 0, cnt = 0;
			f[i] = 1;
			while(sieve[t] != 0) {
				if(prev != sieve[t]) {
					f[i] *= (cnt+1);
					cnt = 0;
					prev = sieve[t];
				}
				cnt++;
				t /= sieve[t];
			}
			if(t == 1) f[i] *= (cnt+1);
			else {
				if(prev == t) f[i] *= (cnt+2);
				else f[i] *= (cnt+1) * 2;
			}
			g[i] = g[f[i]] + 1;
		}
	}

	private static Node merge(Node a, Node b) {
		return new Node(
			a.sum + b.sum,
			Math.max(a.max, b.max)
		);
	}

	private static void pointUpdate(int s, int e, int i, Node v, int n) {
		if(s == e) {
			seg[n] = v;
			return;
		}
		int m = (s+e)>>1;
		if(i <= m) pointUpdate(s,m,i,v,n*2);
		else pointUpdate(m+1,e,i,v,n*2+1);
		seg[n] = merge(seg[n*2], seg[n*2+1]);
	}

	private static void rangeUpdate(int s, int e, int l, int r, int n) {
		if(l>r || l>e || r<s) return;
		if(seg[n].max == 0) return;
		if(s == e) {
			seg[n].sum = f[(int)seg[n].sum];
			seg[n].max = g[(int)seg[n].sum];
			return;
		}
		int m = (s+e)>>1;
		if(seg[n*2].max > 0) rangeUpdate(s,m,l,r,n*2);
		if(seg[n*2+1].max > 0) rangeUpdate(m+1,e,l,r,n*2+1);
		seg[n] = merge(seg[n*2], seg[n*2+1]);
	}

	private static Node find(int s, int e, int l, int r, int n) {
		if(l>r || l>e || r<s) return new Node(0,0);
		if(l<=s && e<=r) return seg[n];
		int m = (s+e)>>1;
		return merge(find(s,m,l,r,n*2), find(m+1,e,l,r,n*2+1));
	}

}