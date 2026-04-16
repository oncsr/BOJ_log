import java.util.*;
import java.io.*;

public class Main {
	
	// IO field
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st = new StringTokenizer("");

	static void nextLine() throws Exception {st = new StringTokenizer(br.readLine());}
	static String nextToken() throws Exception {
		while(!st.hasMoreTokens()) nextLine();
		return st.nextToken();
	}
	static int nextInt() throws Exception { return Integer.parseInt(nextToken()); }
	static long nextLong() throws Exception { return Long.parseLong(nextToken()); }
	static double nextDouble() throws Exception { return Double.parseDouble(nextToken()); }
	static void bwEnd() throws Exception {bw.flush();bw.close();}
	
	// Additional field
	
	static final int INF = (int)1e9 + 7;
	static int N, M, W;
	static List<int[]>[] V;
	static int[] D;
	
	public static void main(String[] args) throws Exception {
		
		for(int TC=nextInt();TC-->0;solve()) ready();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		W = nextInt();
		V = new List[N+1];
		for(int i=1;i<=N;i++) V[i] = new ArrayList<>();
		D = new int[N+1];
		Arrays.fill(D, INF);
		for(int i=0;i<M+W;i++) {
			int a = nextInt(), b = nextInt(), c = nextInt() * (i<M ? 1 : -1);
			V[a].add(new int[] {b,c});
			if(i<M) V[b].add(new int[] {a,c});
		}
		
	}
	
	static void solve() throws Exception {
		
		for(int i=0;i<N;i++) {
			for(int j=1;j<=N;j++) for(int[] e:V[j]) {
				int next = e[0], cost = e[1];
				if(D[next] > D[j] + cost) {
					if(i == N-1) {
						bw.write("YES\n");
						return;
					}
					D[next] = D[j] + cost;
				}
			}
		}
		bw.write("NO\n");
		
	}
	
}