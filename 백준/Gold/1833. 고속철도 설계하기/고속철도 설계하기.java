import java.util.*;
import java.io.*;

class Edge{
	int cost;
	int u;
	int v;
	Edge(int cost, int u, int v){
		this.cost = cost;
		this.u = u;
		this.v = v;
	}
}

public class Main {
	static StringTokenizer st;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static int nextInt() { return Integer.parseInt(st.nextToken()); }
	static void newLine() throws Exception { st = new StringTokenizer(br.readLine()); }

	static int[] r;
	static int f(int x) {return x==r[x] ? x : (r[x]=f(r[x]));}
	
	public static void main(String[] args) throws Exception {

		int N = Integer.parseInt(br.readLine());
		r = new int[N];
		for(int i=0;i<N;i++) r[i] = i;

		int ans = 0, mst_edges = 0;
		ArrayList<Edge> E = new ArrayList<>();
		for(int i=0;i<N;i++) {
			newLine();
			for(int j=0;j<N;j++) {
				int a = nextInt();
				if(j <= i) continue;
				if(a > 0) {
					E.add(new Edge(a,i,j));
					continue;
				}
				ans -= a;
				int x = f(i), y = f(j);
				if(x==y) continue;
				r[x] = y;
				mst_edges++;
			}
		}
		
		ArrayList<Edge> res = new ArrayList<>();
		Collections.sort(E, (a,b) -> a.cost - b.cost);
		for(Edge e : E) {
			int x = f(e.u), y = f(e.v);
			if(x == y) continue;
			res.add(e);
			ans += e.cost;
			r[x] = y;
		}
		bw.write(ans+" "+(res.size())+"\n");
		for(Edge e : res) bw.write((e.u+1) + " " + (e.v+1) + "\n");
		
		bw.close();
	}

}