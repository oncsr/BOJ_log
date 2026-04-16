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
	static int[] a;

	public static void main(String[] args) throws Exception {

		io = new IOController();

		init();
		solve();

		io.close();

	}

	static void init() throws Exception {

		N = io.nextInt();
		a = new int[N];
		for(int i=0;i<N;i++) a[i] = io.nextInt();

	}

	static void solve() throws Exception {

		int ans = Integer.MAX_VALUE;
		for(int s=0;s<=83;s++) {
			int res = 0, e = s+17;
			for(int i=0;i<N;i++) {
				if(a[i] < s) res += (s-a[i])*(s-a[i]);
				if(a[i] > e) res += (a[i]-e)*(a[i]-e);
			}
			ans = Math.min(ans, res);
		}
		io.write(ans + "\n");

	}

}