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

	static int N;

	public static void main(String[] args) throws Exception {

		io = new IOController();

		init();
		solve();

		io.close();

	}

	static void init() throws Exception {

		N = io.nextInt();

	}

	static void solve() throws Exception {

		boolean[][] vis = new boolean[N*2][N*2];
		vis[1][0] = true;
		Queue<int[]> q = new ArrayDeque<>();
		q.offer(new int[]{1,0,0});
		while(!q.isEmpty()) {
			int[] cur = q.poll();
			int n = cur[0], k = cur[1], t = cur[2];
			if(n == N) {
				io.write(t + "\n");
				return;
			}
			if(!vis[n][n]) {
				vis[n][n] = true;
				q.offer(new int[]{n,n,t+1});
			}
			if(n<N && !vis[n+k][k]) {
				vis[n+k][k] = true;
				q.offer(new int[]{n+k,k,t+1});
			}
			if(n>0 && !vis[n-1][k]) {
				vis[n-1][k] = true;
				q.offer(new int[]{n-1,k,t+1});
			}
		}

	}

}