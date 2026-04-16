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
	
	static int N, A, B;
	static boolean[] e;
	
	public static void main(String[] args) throws Exception {
		
		e = new boolean[100001];
		for(int i=2;i*i<=100000;i++) if(!e[i]) for(int j=i*i;j<=100000;j+=i) e[j] = true;
		
		for(int T=nextInt();T-->0;solve()) ready();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		A = nextInt();
		B = nextInt();
		
	}
	
	static void solve() throws Exception {
		
		Queue<int[]> Q = new LinkedList<>();
		boolean[] vis = new boolean[1000001];
		vis[N] = true;
		Q.offer(new int[] {N,0});
		while(!Q.isEmpty()) {
			int[] now = Q.poll();
			int n = now[0], t = now[1];
			if(A<=n && n<=B && !e[n]) {
				bw.write(t + "\n");
				return;
			}
			if(!vis[n/2]) {
				vis[n/2] = true;
				Q.offer(new int[] {n/2,t+1});
			}
			if(!vis[n/3]) {
				vis[n/3] = true;
				Q.offer(new int[] {n/3,t+1});
			}
			if(n<1000000 && !vis[n+1]) {
				vis[n+1] = true;
				Q.offer(new int[] {n+1,t+1});
			}
			if(n>0 && !vis[n-1]) {
				vis[n-1] = true;
				Q.offer(new int[] {n-1,t+1});
			}
		}
		bw.write("-1\n");
		
	}
	
}