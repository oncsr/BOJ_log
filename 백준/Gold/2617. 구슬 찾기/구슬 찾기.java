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

	static int N, M;
	static boolean[][] right, reverse;

	public static void main(String[] args) throws Exception {

		io = new IOController();

		init();
		solve();

		io.close();

	}

	static void init() throws Exception {

		N = io.nextInt();
		M = io.nextInt();
		right = new boolean[N+1][N+1];
		reverse = new boolean[N+1][N+1];
		for(int a,b;M-->0;) {
			a = io.nextInt();
			b = io.nextInt();
			right[a][b] = true;
			reverse[b][a] = true;
		}

	}

	static void solve() throws Exception {

		int ans = 0;
		for(int i=1;i<=N;i++) {

			boolean[] vis = new boolean[N+1];
			int cnt1 = 0;
			Queue<Integer> q = new ArrayDeque<>();
			q.offer(i);
			vis[i] = true;
			while(!q.isEmpty()) {
				int cur = q.poll();
				cnt1++;
				for(int j=1;j<=N;j++) if(right[cur][j] && !vis[j]) {
					vis[j] = true;
					q.offer(j);
				}
			}
			if(cnt1 > N/2+1) ans++;

			vis = new boolean[N+1];
			int cnt2 = 0;
			q.offer(i);
			vis[i] = true;
			while(!q.isEmpty()) {
				int cur = q.poll();
				cnt2++;
				for(int j=1;j<=N;j++) if(reverse[cur][j] && !vis[j]) {
					vis[j] = true;
					q.offer(j);
				}
			}
			if(cnt2 > N/2+1) ans++;

		}
		io.write(ans + "\n");

	}

}