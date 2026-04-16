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
		double d;
		int n;
		Node(double d, int n){
			this.d = d;
			this.n = n;
		}
	}
	
	static int N;
	static double[][] A;
	static double[] start, end;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		start = new double[2];
		end = new double[2];
		for(int i=0;i<2;i++) start[i] = nextDouble();
		for(int i=0;i<2;i++) end[i] = nextDouble();
		
		N = nextInt() + 2;
		A = new double[N][2];
		A[0] = start;
		A[N-1] = end;
		for(int i=1;i<=N-2;i++) for(int j=0;j<2;j++) A[i][j] = nextDouble();
		
	}
	
	static void solve() throws Exception {
		
		PriorityQueue<Node> Q = new PriorityQueue<>((a,b) -> Double.compare(a.d, b.d));
		double[] D = new double[N];
		Arrays.fill(D, Double.MAX_VALUE);
		for(int i=1;i<N;i++) {
			double dist = Math.sqrt((A[0][0]-A[i][0])*(A[0][0]-A[i][0]) + (A[0][1]-A[i][1])*(A[0][1]-A[i][1]));
			D[i] = dist/5;
			Q.offer(new Node(dist/5,i));
		}
		
		while(!Q.isEmpty()) {
			Node now = Q.poll();
			double d = now.d;
			int n = now.n;
			if(n == N-1) {
				bw.write(d + "\n");
				return;
			}
			for(int i=1;i<N;i++) if(i != n) {
				double dist = Math.sqrt((A[n][0]-A[i][0])*(A[n][0]-A[i][0]) + (A[n][1]-A[i][1])*(A[n][1]-A[i][1]));
				double c = d + Math.min(dist/5, 2 + Math.abs(dist-50)/5);
				if(D[i] > c) {
					D[i] = c;
					Q.offer(new Node(D[i],i));
				}
			}
		}
		
	}
	
}