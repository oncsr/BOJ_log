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
		String n;
		int d;
		Node(String n, int d){
			this.n = n;
			this.d = d;
		}
	}
	
	static int N, M;
	static int[] A;
	static int[][] cons;
	static Map<String, Integer> D;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		A = new int[N];
		for(int i=0;i<N;i++) A[i] = nextInt();
		M = nextInt();
		cons = new int[M][3];
		for(int i=0;i<M;i++) {
			cons[i][0] = nextInt()-1;
			cons[i][1] = nextInt()-1;
			cons[i][2] = nextInt();
		}
		D = new TreeMap<>();
		
	}
	
	static void solve() throws Exception {
		
		PriorityQueue<Node> Q = new PriorityQueue<>((a,b) -> a.d-b.d);
		String cur = "";
		for(int i=0;i<N;i++) cur += Integer.toString(i);
		Q.offer(new Node(cur, 0));
		D.put(cur, 0);
		
		while(!Q.isEmpty()) {
			Node now = Q.poll();
			String n = now.n;
			int d = now.d;
			if(d > D.get(n)) continue;
			if(check(n)) {
				bw.write(d + "\n");
				return;
			}
			for(int[] con:cons) {
				int l = con[0], r = con[1], c = con[2];
				String x = "";
				for(int j=0;j<N;j++) {
					if(j == l) x += n.charAt(r);
					else if(j == r) x += n.charAt(l);
					else x += n.charAt(j);
				}
				if(!D.containsKey(x) || D.get(x) > d + c) {
					D.put(x, d+c);
					Q.offer(new Node(x, d+c));
				}
			}
		}
		bw.write("-1");
		
	}
	
	static boolean check(String n) {
		int[] I = new int[N];
		for(int i=0;i<N;i++) I[i] = n.charAt(i)-'0';
		for(int i=1;i<N;i++) if(A[I[i-1]] > A[I[i]]) return false;
		return true;
	}
	
}