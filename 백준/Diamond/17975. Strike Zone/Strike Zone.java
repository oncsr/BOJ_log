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
	
	static class Node{
		int l, r, t, s;
		Node(){}
		Node(int l, int r, int t, int s){
			this.l = l;
			this.r = r;
			this.t = t;
			this.s = s;
		}
	}
	
	static final int INF = -(int)1e9 - 7;
	static int N, C1, C2;
	static List<int[]> points;
	static Node[] seg;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		points = new ArrayList<>();
		N = nextInt();
		for(int i=0;i<N;i++) points.add(new int[] {nextInt(), nextInt(), 1});
		int temp = nextInt();
		N += temp;
		for(int i=0;i<temp;i++) points.add(new int[] {nextInt(), nextInt(), -1});
		C1 = nextInt();
		C2 = nextInt();
		for(int[] p:points) p[2] = p[2] == 1 ? C1 : -C2;
		
		Collections.sort(points, (a,b) -> a[0]==b[0] ? a[1]-b[1] : a[0]-b[0]);
		int x = 1;
		for(int i=0;i<N;) {
			int cur = points.get(i)[0];
			while(i<N && points.get(i)[0]==cur) {
				points.get(i)[0] = x;
				i++;
			}
			x++;
		}
		
	}
	
	static void solve() throws Exception {
		
		Collections.sort(points, (a,b) -> a[1]==b[1] ? a[0]-b[0] : a[1]-b[1]);
		
		int ans = Integer.MIN_VALUE;
		for(int i=0;i<N;i++) {
			int res = points.get(i)[2];
			seg = new Node[N*4];
			init(1,N,1);
			for(int j=i;j<N;) {
				int y = points.get(j)[1];
				while(j<N && points.get(j)[1]==y) {
					upt(1,N,points.get(j)[0],points.get(j)[2],1);
					j++;
				}
				res = Math.max(res, seg[1].t);
			}
			ans = Math.max(ans, res);
		}
		bw.write(ans + "\n");
		
	}
	
	static Node mrg(Node a, Node b) {
		Node c = new Node();
		c.l = Math.max(a.l, a.s + b.l);
		c.r = Math.max(b.r, b.s + a.r);
		c.s = a.s + b.s;
		c.t = Math.max(a.r + b.l, Math.max(a.t, b.t));
		return c;
	}
	
	static void init(int s, int e, int n) {
		if(s==e) {
			seg[n] = new Node(0,0,0,0);
			return;
		}
		int m=(s+e)>>1;
		init(s,m,n*2);
		init(m+1,e,n*2+1);
		seg[n] = mrg(seg[n*2], seg[n*2+1]);
	}
	
	static void upt(int s, int e, int i, int v, int n) {
		if(s==e) {
			seg[n] = new Node(v,v,v,v);
			return;
		}
		int m=(s+e)>>1;
		if(i<=m) upt(s,m,i,v,n*2);
		else upt(m+1,e,i,v,n*2+1);
		seg[n] = mrg(seg[n*2], seg[n*2+1]);
	}
	
}