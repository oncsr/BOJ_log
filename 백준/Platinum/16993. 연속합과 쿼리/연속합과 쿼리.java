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
	
	static final int INF = -((int)1e9 + 7);
	
	static class Node{
		int left, right, tot, sum;
		Node(){
			left = 0;
			right = 0;
			tot = 0;
			sum = 0;
		}
		Node(int left, int right, int tot, int sum){
			this.left = left;
			this.right = right;
			this.tot = tot;
			this.sum = sum;
		}
	}
	
	static int N, M;
	static int[] A;
	static Node[] seg;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		seg = new Node[4*N];
		A = new int[N+1];
		for(int i=1;i<=N;i++) A[i] = nextInt();
		
	}
	
	static void solve() throws Exception {
		
		init(1,N,1);
		for(M = nextInt();M-->0;) bw.write(query(1,N,nextInt(),nextInt(),1).tot + "\n");
		
	}
	
	static Node merge(Node a, Node b) {
		int left = Math.max(a.left, a.sum + b.left);
		int right = Math.max(b.right, b.sum + a.right);
		int tot = Math.max(a.right + b.left, Math.max(a.tot, b.tot));
		int sum = a.sum + b.sum;
		return new Node(left,right,tot,sum);
	}
	
	static Node init(int s, int e, int n) {
		if(s == e) return seg[n] = new Node(A[s],A[s],A[s],A[s]);
		int m=(s+e)>>1;
		return seg[n] = merge(init(s,m,n*2), init(m+1,e,n*2+1));
	}
	
	static Node query(int s, int e, int l, int r, int n) {
		if(l>r || l>e || r<s) return new Node(INF,INF,INF,0);
		if(l<=s && e<=r) return seg[n];
		int m=(s+e)>>1;
		return merge(query(s,m,l,r,n*2), query(m+1,e,l,r,n*2+1));
	}
	
}