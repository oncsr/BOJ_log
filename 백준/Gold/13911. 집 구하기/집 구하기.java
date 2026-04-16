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

	static int N, M;
	static List<int[]>[] graph;
	static boolean[] cant;

	public static void main(String[] args) throws Exception {

		io = new IOController();

		N = io.nextInt();
		M = io.nextInt();
		graph = new List[N+1];
		cant = new boolean[N+1];
		for(int i=1;i<=N;i++) graph[i] = new ArrayList<>();

		for(int i=0;i<M;i++) {
			int a = io.nextInt();
			int b = io.nextInt();
			int c = io.nextInt();
			graph[a].add(new int[]{b,c});
			graph[b].add(new int[]{a,c});
		}

		int c1 = io.nextInt(), x = io.nextInt();
		int[] r1 = new int[c1];
		for(int i=0;i<c1;i++) {
			r1[i] = io.nextInt();
			cant[r1[i]] = true;
		}
		int[] mc = dijk(r1);

		int c2 = io.nextInt(), y = io.nextInt();
		int[] r2 = new int[c2];
		for(int i=0;i<c2;i++) {
			r2[i] = io.nextInt();
			cant[r2[i]] = true;
		}
		int[] sb = dijk(r2);

		int ans = INF;
		for(int i=1;i<=N;i++) if(!cant[i] && mc[i] <= x && sb[i] <= y) ans = Math.min(ans, mc[i] + sb[i]);
		io.write((ans == INF ? -1 : ans) + "\n");

		io.close();

	}

	static int[] dijk(int[] start) {
		int[] dist = new int[N+1];
		Arrays.fill(dist, INF);
		PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> a[0]-b[0]);
		for(int s:start) {
			dist[s] = 0;
			pq.offer(new int[]{0,s});
		}

		while(!pq.isEmpty()) {
			int[] cur = pq.poll();
			int d = cur[0], n = cur[1];
			if(d > dist[n]) continue;
			for(int[] e:graph[n]) {
				int i = e[0], c = e[1];
				if(dist[i] > d+c) {
					dist[i] = d+c;
					pq.offer(new int[]{dist[i],i});
				}
			}
		}

		return dist;
	}

}