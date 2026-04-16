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
	
	static int M, N, x, y;
	
	public static void main(String[] args) throws Exception {
		
		for(int T=nextInt();T-->0;solve()) ready();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		M = nextInt();
		N = nextInt();
		x = nextInt();
		y = nextInt();
		
	}
	
	static void solve() throws Exception{
		
		for(int p=0;p<=N;p++) {
			int right = M*p + x-y;
			if(right % N == 0) {
				bw.write((x+M*p) + "\n");
				return;
			}
		}
		bw.write("-1\n");
		
	}
	
}