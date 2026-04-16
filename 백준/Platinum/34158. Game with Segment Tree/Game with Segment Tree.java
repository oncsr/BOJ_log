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

	static int K;
	static int[] g;
	static List<Integer> list;

	public static void main(String[] args) throws Exception {

		io = new IOController();

		K = io.nextInt();
		g = new int[K];
		g[0] = 1;
		for(int i=1;i<K;i++) {
			TreeSet<Integer> tmp = new TreeSet<>();
			int xor = 0;
			for(int j=i-1;j>=0;j--) {
				xor ^= g[j];
				tmp.add(xor);
			}
			int mex = 1;
			for(int x:tmp) if(mex == x) mex++; else break;
			g[i] = mex;
		}

		for(int T=io.nextInt();T-->0;) {
			long a = io.nextLong();
			long b = io.nextLong();
			list = new ArrayList<>();

			get(1,(1L<<(K-1)),a,b,K-1);
			int xor = 0;
			for(int x:list) xor ^= g[x];

			if(xor != 0) io.write("swlee0202\n");
			else io.write("mj1000j\n");
		}

		io.close();

	}

	static void get(long s, long e, long l, long r, int d) {
		if(l>r || l>e || r<s) return;
		if(l<=s && e<=r) {
			list.add(d);
			return;
		}
		long m = (s+e)>>1;
		get(s,m,l,r,d-1);
		get(m+1,e,l,r,d-1);
	}

}