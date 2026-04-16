import java.util.*;
import java.io.*;

class Edge{
	int c,a,b;
	Edge(int c, int a, int b){
		this.c = c;
		this.a = a;
		this.b = b;
	}
}

class Main {
	
	// IO field
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;

	static void nextLine() throws Exception {st = new StringTokenizer(br.readLine());}
	static int nextInt() {return Integer.parseInt(st.nextToken());}
	static long nextLong() {return Long.parseLong(st.nextToken());}
	static void bwEnd() throws Exception {bw.flush();bw.close();}
	
	// Additional field
	static int[] r;
	static ArrayList<Integer>[] V;
	static int[][] par = new int[200001][18];
	static int[] dep = new int[200001];
	
	static int f(int x) {return x==r[x] ? x : (r[x]=f(r[x]));}
	
	static void dfs(int n, int p, int d) {
		par[n][0] = p;
		dep[n] = d;
		for(int i : V[n]) {
			if(i == p) continue;
			dfs(i,n,d+1);
		}
	}
	
	public static void main(String[] args) throws Exception {

		nextLine();
		int N = nextInt(), M = nextInt();
		
		V = new ArrayList[N+1];
		r = new int[N+1];
		for(int i=1;i<=N;i++) {
			V[i] = new ArrayList<>();
			r[i] = i;
		}
		
		Edge[] E = new Edge[M];
		for(int i=0;i<M;i++) {
			nextLine();
			int a = nextInt(), b = nextInt();
			E[i] = new Edge(i,a,b);
		}
		Arrays.sort(E, (a,b) -> a.c - b.c);
		
		for(Edge e : E) {
			int x = f(e.a), y = f(e.b);
			if(x == y) continue;
			r[x] = y;
			V[e.a].add(e.b);
			V[e.b].add(e.a);
		}
		dfs(1,0,0);
		
		for(int k=1;k<18;k++) for(int i=1;i<=N;i++) par[i][k] = par[par[i][k-1]][k-1];
		
		nextLine();
		int Q = nextInt();
		while(Q-- > 0) {
			nextLine();
			int a = nextInt(), b = nextInt();
			int ans = -1;
			while(dep[a] != dep[b]) {
				if(dep[a] > dep[b]) {
					int diff = dep[a] - dep[b];
					ans += diff;
					for(int g=0;g<18;g++) {
						if(((1<<g)&diff) != 0) a = par[a][g];						
					}
				}
				else {
					int diff = dep[b] - dep[a];
					ans += diff;
					for(int g=0;g<18;g++) {
						if(((1<<g)&diff) != 0) b = par[b][g];						
					}
				}
			}
			
			while(par[a][0] != par[b][0]) {
				for(int k=17;k>=0;k--) {
					if((1<<k) > dep[a]) continue;
					if(par[a][k] != par[b][k]) {
						ans += (1<<k) * 2;
						a = par[a][k];
						b = par[b][k];						
					}
					if(par[a][0] == par[b][0]) break;
				}
			}
			if(a != b) ans += 2;
			
			
			bw.write(ans+"\n");
		}
		
		bwEnd();
	}

}