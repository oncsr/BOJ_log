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
	
	static int N, M;
	static int[] x, y, root;
	static List<int[]>[] graph;
	static int restaurent = -1, cafe = -1;
	
	static final int INF = (int)1e9 + 7;
	
	static int f(int x){return x==root[x] ? x : (root[x]=f(root[x]));}
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		x = new int[N+1];
		y = new int[N+1];
		root = new int[N+1];
		graph = new List[N+1];
		for(int i=1;i<=N;i++) {
		    graph[i] = new ArrayList<>();
		    root[i] = i;
		}
		
		for(int i=1;i<=N;i++) {
		    x[i] = nextInt();
		    if(x[i] == 0) x[i] = INF;
		}
		for(int i=1;i<=N;i++) {
		    y[i] = nextInt();
		    if(y[i] == 0) y[i] = INF;
		}
		
		for(int i=0;i<M;i++){
		    int u = nextInt(), v = nextInt(), w = nextInt();
		    graph[u].add(new int[]{v,w});
		    graph[v].add(new int[]{u,w});
		    int a = f(u), b = f(v);
		    if(a == b) continue;
		    root[a] = b;
		}
		
	}
	
	static void solve() throws Exception{
		
		int restaurentCost = INF, cafeCost = INF, R = f(1);
		for(int i=1;i<=N;i++) if(f(i) == R) {
		    if(x[i] < restaurentCost) {
		        restaurentCost = x[i];
		        restaurent = i;
		    }
		    if(y[i] < cafeCost){
		        cafeCost = y[i];
		        cafe = i;
		    }
		}
		
		int[] distFromStart = dijkstra(1);
		int[] distFromRestaurent = dijkstra(restaurent);
		
		int res = 0;
		if(restaurent == cafe) res = distFromStart[restaurent] * 2;
		else res = distFromStart[restaurent] + distFromStart[cafe] + distFromRestaurent[cafe];
		
		bw.write(res + "\n");
		
	}
	
	static int[] dijkstra(int start){
	    
	    int[] dist = new int[N+1];
	    Arrays.fill(dist, INF);
	    PriorityQueue<int[]> Q = new PriorityQueue<>((a,b) -> a[0]-b[0]);
	    dist[start] = 0;
	    Q.offer(new int[]{0,start});
	    while(!Q.isEmpty()){
	        int[] now = Q.poll();
	        int d = now[0], n = now[1];
	        if(d > dist[n]) continue;
	        for(int[] next:graph[n]){
	            int i = next[0], c = next[1];
	            if(dist[i] > d+c){
	                dist[i] = d+c;
	                Q.offer(new int[]{dist[i],i});
	            }
	        }
	    }
	    return dist;
	    
	}
	
}
