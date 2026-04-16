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
	
	static int N, M, K;
	static List<Integer>[] V;
	static boolean[] vis;
	static Queue<Integer> Q;
	static int cnt = -1;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt() + 1;
		M = nextInt();
		K = nextInt();
		V = new List[N+1];
		for(int i=1;i<=N;i++) V[i] = new ArrayList<>();
		vis = new boolean[N+1];
		Q = new LinkedList<>();
		
		for(int i=0;i<M;i++){
		    int a = nextInt(), b = nextInt();
		    V[a].add(b);
		    V[b].add(a);
		}
		
		for(int i=0;i<K;i++) vis[nextInt()] = true;
		
	}
	
	static void solve() throws Exception{
		
		Q.offer(1);
		vis[1] = true;
		while(!Q.isEmpty()){
		    int n = Q.poll();
		    cnt++;
		    for(int i:V[n]) if(!vis[i]){
		        vis[i] = true;
		        Q.offer(i);
		    }
		}
		bw.write(cnt + "\n");
		
	}
	
}
