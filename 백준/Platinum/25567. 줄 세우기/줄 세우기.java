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
	
	static int N, Q;
	static long[] S;
	static int[] C, O;
	static Deque<Integer>[] V, T;
	static int[][] queries;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		S = new long[200001];
		C = new int[200001];
		O = new int[200001];
		
		N = nextInt();
		V = new Deque[N+1];
		T = new Deque[N+1];
		for(int i=1;i<=N;i++) {
			V[i] = new ArrayDeque<>();
			T[i] = new ArrayDeque<>();
			for(int j=nextInt();j-->0;) {
				int a = nextInt();
				V[i].addLast(a);
				T[i].addLast(a);
				C[a] = i;
				O[a] = i;
			}
		}
		
		Q = nextInt();
		queries = new int[Q][3];
		for(int i=0;i<Q;i++) for(int j=0;j<3;j++) queries[i][j] = nextInt();
		
	}
	
	static void solve() throws Exception {
		
		// T, O 처리
		
		boolean[] vis = new boolean[N+1];
		for(int[] query : queries) if(query[0] == 1) {
			int a = query[1], b = query[2];
			if(O[a] == O[b]) continue;
			int x = O[a], y = O[b];
			
			if(T[x].size() < T[y].size()) {
				while(!T[x].isEmpty()) {
					int g = T[x].pollLast();
					T[y].addFirst(g);
					O[g] = y;
				}
				vis[x] = true;
			}
			else {
				while(!T[y].isEmpty()) {
					int g = T[y].pollFirst();
					T[x].addLast(g);
					O[g] = x;
				}
				vis[y] = true;
			}
		}
		for(int i=1;i<=N;i++) if(!vis[i]) {
			vis[i] = true;
			long s = 0;
			while(!T[i].isEmpty()) {
				int a = T[i].pollFirst();
				s += a;
				S[a] = s;
			}
		}
		// 
		
		for(int[] query:queries) {
			int o = query[0], a = query[1], b = query[2];
			if(o == 1) {
				if(C[a] == C[b]) bw.write("NO\n");
				else {
					bw.write("YES\n");
					int x = C[a], y = C[b];
					
					if(V[x].size() < V[y].size()) {
						while(!V[x].isEmpty()) {
							int g = V[x].pollLast();
							V[y].addFirst(g);
							C[g] = y;
						}
					}
					else {
						while(!V[y].isEmpty()) {
							int g = V[y].pollFirst();
							V[x].addLast(g);
							C[g] = x;
						}
					}
				}
			}
			else {
				if(C[a] == C[b]) {
                    if(S[b] > S[a]) bw.write((S[b]-S[a]+a) + "\n");
                    else bw.write((S[a]-S[b]+b) + "\n");
                }
				else bw.write("-1\n");
			}
		}
		
	}
	
}