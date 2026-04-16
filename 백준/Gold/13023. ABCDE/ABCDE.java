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
	static List<Integer>[] V;
	static int ans = 0;
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		V = new List[N];
		for(int i=0;i<N;i++) V[i] = new ArrayList<>();
		for(int i=0;i<M;i++) {
			int a = nextInt(), b = nextInt();
			V[a].add(b);
			V[b].add(a);
		}
		
	}
	
	static void solve() throws Exception{

		for(int i=0;i<N;i++) {
			for(int j=0;j<V[i].size();j++) for(int k=j+1;k<V[i].size();k++) {
				int a = V[i].get(j), b = V[i].get(k);
				if(V[a].size() + V[b].size() < 4) continue;
				if(V[a].size() == 1 || V[b].size() == 1) continue;
				if(V[a].size() == 2) {
					boolean con = false;
					for(int x:V[a]) if(x == b) con = true;
					if(con) continue;
				}
				if(V[b].size() == 2) {
					boolean con = false;
					for(int y:V[b]) if(y == a) con = true;
					if(con) continue;
				}
				if(V[a].size() + V[b].size() > 6) ans = 1;
				else {
					int d = -1, e = -1;
					for(int x:V[a]) if(x != i && x != b) for(int y:V[b]) if(y != i && y != a) if(x != y) ans = 1;
				}
			}
			
		}
		bw.write(ans + "\n");
		
	}
	
}