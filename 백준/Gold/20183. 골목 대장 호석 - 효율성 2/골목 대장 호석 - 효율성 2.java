import java.util.*;
import java.io.*;

class Main {
	
	// IO field
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st = new StringTokenizer("");

	static void nextLine() throws Exception {st = new StringTokenizer(br.readLine());}
	static int nextInt() throws Exception {
		if(!st.hasMoreTokens()) nextLine();
		return Integer.parseInt(st.nextToken());
	}
	static long nextLong() throws Exception {
		if(!st.hasMoreTokens()) nextLine();
		return Long.parseLong(st.nextToken());
	}
	static void bwEnd() throws Exception {bw.flush();bw.close();}
	
	// Additional field
	
	static int N, M, A, B;
	static long C;
	static List<int[]>[] V;
	static final long INF = (long)1e18;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		A = nextInt();
		B = nextInt();
		C = nextLong();
		V = new List[N+1];
		for(int i=1;i<=N;i++) V[i] = new ArrayList<>();
		
		for(int i=0;i<M;i++) {
			int a = nextInt(), b = nextInt(), c = nextInt();
			V[a].add(new int[] {b,c});
			V[b].add(new int[] {a,c});
		}
		
	}
	
	static void solve() throws Exception{
		
		long s = 0, e = (long)1e9 + 1, m = (s+e)>>1;
		while(s<e) {
			
			PriorityQueue<long[]> Q = new PriorityQueue<>((a,b) -> {
				if(a[0]>b[0]) return 1;
				if(a[0]<b[0]) return -1;
				return 0;
			});
			long[] D = new long[N+1];
			Arrays.fill(D, INF);
			Q.offer(new long[] {0,A});
			D[A] = 0;
			while(!Q.isEmpty()) {
				long[] now = Q.poll();
				long d = now[0];
				int n = (int)now[1];
				if(d > D[n]) continue;
				for(int[] g:V[n]) {
					int i = g[0], c = g[1];
					if(c <= m && D[i] > d+c) {
						D[i] = d+c;
						Q.offer(new long[] {D[i],i});
					}
				}
			}
			
			if(D[B] <= C) e = m;
			else s = m+1;
			m = (s+e)>>1;
			
		}
		
		bw.write((m == (long)1e9 + 1 ? -1 : m) + "\n");
		
	}
	
}