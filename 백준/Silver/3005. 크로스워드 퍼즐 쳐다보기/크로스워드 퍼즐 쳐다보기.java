import java.util.*;
import java.io.*;


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
	
	static PriorityQueue<String> Q = new PriorityQueue<>();
	static int R, C;
	static char[][] A;
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		nextLine();
		R = nextInt();
		C = nextInt();
		A = new char[R][];
		for(int i=0;i<R;i++) A[i] = br.readLine().toCharArray();
		
	}
	
	static void solve() throws Exception{
		
		for(int i=0;i<R;i++) {
			String cur = "";
			for(int j=0;j<C;j++) {
				if(A[i][j] == '#') {
					if(cur.length() > 1) Q.offer(cur);
					cur = "";
				}
				else cur += A[i][j];
			}
			if(cur.length() > 1) Q.offer(cur);
		}
		
		for(int j=0;j<C;j++) {
			String cur = "";
			for(int i=0;i<R;i++) {
				if(A[i][j] == '#') {
					if(cur.length() > 1) Q.offer(cur);
					cur = "";
				}
				else cur += A[i][j];
			}
			if(cur.length() > 1) Q.offer(cur);
		}
		
		bw.write(Q.poll());
		
	}
	
}