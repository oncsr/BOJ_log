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
	static int[] towns;
	static int[][] dist, min;
	static List<int[]>[] graph;
	static int ans = Integer.MAX_VALUE;

	public static void main(String[] args) throws Exception {

		io = new IOController();

		init();
		solve();

		io.close();

	}

	static void init() throws Exception {

		N = io.nextInt();
		M = io.nextInt();
		K = io.nextInt();
		towns = new int[K];
		for(int i=0;i<K;i++) towns[i] = io.nextInt();
		dist = new int[N+1][K];
		graph = new List[N+1];
		for(int i=1;i<=N;i++) graph[i] = new ArrayList<>();
		for(int i=0;i<M;i++) {
			int a = io.nextInt();
			int b = io.nextInt();
			int c = io.nextInt();
			graph[a].add(new int[]{b,c});
			graph[b].add(new int[]{a,c});
		}
		min = new int[K][K];
		for(int i=0;i<K;i++) Arrays.fill(min[i], INF);

	}

	static void solve() throws Exception {

		for(int i=0;i<K;i++) dijk(i);
		for(int i=0;i<K;i++) for(int j=0;j<K;j++) if(i != j) {
			perm(i, j, (1<<i) | (1<<j), dist[towns[i]][j]);
		}

		int ans = Integer.MAX_VALUE;
		for(int x=1;x<=N;x++) {
			boolean can = true;
			for(int i=0;i<K;i++) if(towns[i] == x) can = false;
			if(!can) continue;
			for(int i=0;i<K;i++) for(int j=0;j<K;j++) if(i != j) {

				ans = Math.min(ans, dist[x][i] + min[i][j] + dist[x][j]);
			}
		}
		io.write(ans + "\n");

	}

	static void dijk(int k) {
		int start = towns[k];
		PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> a[0]-b[0]);
		for(int i=1;i<=N;i++) dist[i][k] = INF;
		dist[start][k] = 0;
		pq.offer(new int[]{0, start});
		while(!pq.isEmpty()) {
			int[] cur = pq.poll();
			int d = cur[0], n = cur[1];
			if(d > dist[n][k]) continue;
			for(int[] e:graph[n]) {
				int next = e[0], cost = d + e[1];
				if(dist[next][k] > cost) {
					dist[next][k] = cost;
					pq.offer(new int[]{cost, next});
				}
			}
		}
	}

	static void perm(int start, int prev, int state, int total) {
		if(state == (1<<K) - 1) {
			min[start][prev] = Math.min(min[start][prev], total);
			return;
		}

		for(int i=0;i<K;i++) if((state & (1<<i)) == 0) {
			perm(start, i, state | (1<<i), total + dist[towns[prev]][i]);
		}
	}

}