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
	
	static int N;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		
	}
	
	static void solve() throws Exception{

		int res = 0;
		for(int i=0;i<N;i++) res ^= D(nextLong());
		bw.write(res==0 ? "cubelover" : "koosaga");
		
	}
	
	static int D(long x) {
		int g = -1;
		
		if(x <= 3) g = 0;
		else if(x <= 15) g = 1;
		else if(x <= 81) g = 2;
		else if(x <= 6723) g = 0;
		else if(x <= 50625) g = 3;
		else if(x <= 2562991875L) g = 1;
		else g = 2;
		
		return g;
	}
	
}