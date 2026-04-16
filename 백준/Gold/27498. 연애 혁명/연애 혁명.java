import java.util.*;
import java.io.*;

class Edge{
	int c, u, v;
	Edge(int c, int u, int v){
		this.c = c;
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
	
	static int[] r = new int[10001];
	static int f(int x) {return x==r[x] ? x : (r[x]=f(r[x]));}
	
	public static void main(String[] args) throws Exception {

		newLine();
		int N = nextInt(), M = nextInt();
		for(int i=1;i<=N;i++) r[i] = i;
		
		ArrayList<Edge> E = new ArrayList<>();
		int ans = 0;
		for(int i=0;i<M;i++) {
			newLine();
			int a = nextInt(), b = nextInt(), c = nextInt(), d = nextInt();
			if(d == 1) {
				int x = f(a), y = f(b);
				r[x] = y;
			}
			else {
				E.add(new Edge(c,a,b));
				ans += c;
			}
		}
		Collections.sort(E, (a,b) -> b.c - a.c);
		
		for(Edge e : E) {
			int x = f(e.u), y = f(e.v);
			if(x == y) continue;
			r[x] = y;
			ans -= e.c;
		}
		bw.write(ans+"\n");
		bw.close();
	}

}