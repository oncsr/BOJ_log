import java.util.*;
import java.io.*;

class Main {
	
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
	static List<int[]>[] V;
	static final int INF = (int)2e9;
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		V = new List[N+1];
		for(int i=1;i<=N;i++) V[i] = new ArrayList<>();
		for(int i=0;i<M;i++){
		    int a = nextInt(), b = nextInt(), c = nextInt();
		    V[a].add(new int[]{b,c*2});
		    V[b].add(new int[]{a,c*2});
		}

	}
	
	static void solve() throws Exception{
		
		int[] DA = new int[N+1];
		Arrays.fill(DA, INF);
		DA[1] = 0;
		PriorityQueue<int[]> Q = new PriorityQueue<>((a,b) -> a[0]-b[0]);
		Q.offer(new int[]{0,1});
		
		while(!Q.isEmpty()){
		    int[] now = Q.poll();
		    int d = now[0], n = now[1];
		    if(d > DA[n]) continue;
		    for(int[] next:V[n]){
		        int i = next[0], c = next[1];
		        if(DA[i] > d+c){
		            DA[i] = d+c;
		            Q.offer(new int[]{DA[i],i});
		        }
		    }
		}
		
		int[][] DB = new int[N+1][2];
		for(int i=1;i<=N;i++) Arrays.fill(DB[i], INF);
		DB[1][0] = 0;
		Q = new PriorityQueue<>((a,b) -> a[0]/2 + a[1]*2 - b[0]/2 - b[1]*2);
		Q.offer(new int[]{0,0,1,0});
		while(!Q.isEmpty()){
		    int[] now = Q.poll();
		    int a = now[0], b = now[1], n = now[2], k = now[3];
		    if(a/2 + b*2 > DB[n][k]) continue;
		    for(int[] next:V[n]){
		        int i = next[0], c = next[1];
		        int res = a/2 + b*2;
		        if(k == 0){
		            res += c/2;
    		        if(DB[i][k^1] > res){
    		            DB[i][k^1] = res;
    		            Q.offer(new int[]{a+c,b,i,k^1});
    		        }
		        }
		        else{
		            res += c*2;
		            if(DB[i][k^1] > res){
		                DB[i][k^1] = res;
		                Q.offer(new int[]{a,b+c,i,k^1});
		            }
		        }
		    }
		}
		
		int ans = 0;
		for(int i=2;i<=N;i++){
		    int a = DA[i], b = Math.min(DB[i][0], DB[i][1]);
		    if(a < b) ans++;
		}
		bw.write(ans + "\n");
		
	}
	
}