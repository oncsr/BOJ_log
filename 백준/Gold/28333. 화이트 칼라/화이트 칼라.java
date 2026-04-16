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
	
	static int N, M;
	static List<Integer>[] P, Q;
	
	public static void main(String[] args) throws Exception {
		
		for(int T=nextInt();T-->0;solve()) ready();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		P = new List[N+1];
		Q = new List[N+1];
		for(int i=1;i<=N;i++) {
			P[i] = new ArrayList<>();
			Q[i] = new ArrayList<>();
		}
		for(int i=0;i<M;i++) {
			int a = nextInt(), b = nextInt();
			P[a].add(b);
			Q[b].add(a);
		}
		
	}
	
	static void solve() throws Exception {
		
		int[] A = bfs(P, 1);
		int[] B = bfs(Q, N);
		for(int i=1;i<=N;i++) if(A[i] + B[i] == A[N]) bw.write(i + " ");
		bw.write("\n");
		
	}
	
	static int[] bfs(List<Integer>[] V, int x) {
		int[] R = new int[N+1];
		Arrays.fill(R, INF);
		Queue<int[]> Q = new LinkedList<>();
		Q.offer(new int[] {x,0});
		R[x] = 0;
		while(!Q.isEmpty()) {
			int[] now = Q.poll();
			int n = now[0], d = now[1];
			for(int i:V[n]) if(R[i] > d+1) {
				R[i] = d+1;
				Q.offer(new int[] {i,R[i]});
			}
		}
		return R;
	}
	
}