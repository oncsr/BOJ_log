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

	static final int INF = (int)1e9 + 7;

	static int N, M, K;
	static int[][] cost;
	static int[] v;

	public static void main(String[] args) throws Exception {

		io = new IOController();

		init();
		solve();

		io.close();

	}

	static void init() throws Exception {

		N = io.nextInt();
		M = io.nextInt();
		cost = new int[N+1][N+1];
		for(int i=1;i<=N;i++) {
			Arrays.fill(cost[i], INF);
			cost[i][i] = 0;
		}
		for(int i=0;i<M;i++) {
			int a = io.nextInt();
			int b = io.nextInt();
			int c = io.nextInt();
			cost[a][b] = Math.min(cost[a][b], c);
		}
		K = io.nextInt();
		v = new int[K];
		for(int i=0;i<K;i++) v[i] = io.nextInt();

	}

	static void solve() throws Exception {

		for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) for(int k=1;k<=N;k++) cost[j][k] = Math.min(cost[j][k], cost[j][i] + cost[i][k]);

		int min = Integer.MAX_VALUE;
		List<Integer> ans = new ArrayList<>();
		for(int x=1;x<=N;x++) {
			int res = 0;
			for(int i:v) res = Math.max(res, cost[x][i] + cost[i][x]);
			if(res < min) {
				ans = new ArrayList<>();
				ans.add(x);
				min = res;
			}
			else if(res == min) {
				ans.add(x);
			}
		}
		for(int i:ans) io.write(i + " ");

	}

}