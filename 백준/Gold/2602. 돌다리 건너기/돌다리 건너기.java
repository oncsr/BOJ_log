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

	static char[] a, b, c;

	public static void main(String[] args) throws Exception {

		io = new IOController();

		init();
		solve();

		io.close();

	}

	static void init() throws Exception {

		a = ('-' + io.nextLine() + '*').toCharArray();
		b = ('-' + io.nextLine() + '*').toCharArray();
		c = ('-' + io.nextLine() + '*').toCharArray();

	}

	static void solve() throws Exception {

		int M = a.length;
		int N = b.length;
		int[][] up = new int[N][M];
		int[][] down = new int[N][M];

		up[0][0] = 1;
		down[0][0] = 1;
		for(int i=1;i<N;i++) {
			for(int j=1;j<M;j++) {
				if(b[i] == a[j]) for(int k=0;k<i;k++) up[i][j] += down[k][j-1];
				if(c[i] == a[j]) for(int k=0;k<i;k++) down[i][j] += up[k][j-1];
			}
		}
		io.write((up[N-1][M-1] + down[N-1][M-1]) + "\n");

	}

}