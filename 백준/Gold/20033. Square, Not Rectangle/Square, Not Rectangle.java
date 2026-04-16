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
	static int[] H;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		H = new int[N];
		for(int i=0;i<N;i++) H[i] = nextInt();

	}
	
	static void solve() throws Exception{
		
		int s = 1, e = N, m = (s+e+1)>>1;
		while(s<e) {
			boolean valid = false;
			
			int cnt = 0;
			for(int i=0;i<N;i++) {
				if(H[i] >= m) cnt++;
				else cnt = 0;
				if(cnt >= m) valid = true;
			}
			
			if(valid) s = m;
			else e = m-1;
			m = (s+e+1)>>1;
		}
		bw.write(m + "\n");
		
	}
	
}