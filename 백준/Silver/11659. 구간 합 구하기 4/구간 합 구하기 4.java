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
	static int N, M;
	static int[] A;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		nextLine();
		N = nextInt();
		M = nextInt();
		A = new int[N+1];
		
		nextLine();
		for(int i=1;i<=N;i++) A[i] = nextInt() + A[i-1];
		
		
	}
	
	static void solve() throws Exception{

		for(int i=1;i<=M;i++) {
			nextLine();
			int a = nextInt(), b = nextInt();
			bw.write((A[b] - A[a-1]) + "\n");
		}
		
		
	}
	
}