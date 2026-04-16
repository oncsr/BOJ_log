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

	static final long INF = (long)1e18 + 7;

	static int N, K;
	static int[][] x, y;
	static int[] z;
	static List<int[]>[] graph;

	public static void main(String[] args) throws Exception {

		io = new IOController();

		init();
		solve();

		io.close();

	}

	static void init() throws Exception {

		N = io.nextInt();
		K = io.nextInt();
		x = new int[N][];
		y = new int[N][];
		z = new int[N];
		for(int i=0;i<N;i++) {
			int X = io.nextInt();
			int Y = io.nextInt();
			int Z = io.nextInt();
			x[i] = new int[]{i,X};
			y[i] = new int[]{i,Y};
			z[i] = Z;
		}
		graph = new List[N+K];
		for(int i=0;i<N+K;i++) graph[i] = new ArrayList<>();

	}

	static void solve() throws Exception {

		Arrays.sort(x, (a,b) -> a[1]==b[1] ? a[0]-b[0] : a[1]-b[1]);
		Arrays.sort(y, (a,b) -> a[1]==b[1] ? a[0]-b[0] : a[1]-b[1]);

		for(int i=1;i<N;i++) {
			int costX = x[i][1]-x[i-1][1];
			graph[x[i][0]].add(new int[]{x[i-1][0], costX});
			graph[x[i-1][0]].add(new int[]{x[i][0], costX});
			int costY = y[i][1]-y[i-1][1];
			graph[y[i][0]].add(new int[]{y[i-1][0], costY});
			graph[y[i-1][0]].add(new int[]{y[i][0], costY});
		}

		for(int i=0;i<N;i++) {
			int Z = z[i]%K, OZ = (K-Z)%K;
			graph[i].add(new int[]{N+Z, z[i]});
			graph[N+OZ].add(new int[]{i, z[i]});
		}

		PriorityQueue<long[]> pq = new PriorityQueue<>((a,b) -> Long.compare(a[0],b[0]));
		long[] dist = new long[N+K];
		Arrays.fill(dist, INF);
		dist[0] = 0;
		pq.offer(new long[]{0,0});
		while(!pq.isEmpty()) {
			long[] cur = pq.poll();
			int n = (int)cur[1];
			long d = cur[0];
			if(d > dist[n]) continue;
			for(int[] e:graph[n]) {
				int next = e[0];
				long cost = d + e[1];
				if(dist[next] > cost) {
					dist[next] = cost;
					pq.offer(new long[]{cost, next});
				}
			}
		}

		for(int i=0;i<N;i++) io.write(dist[i] + "\n");

	}

}