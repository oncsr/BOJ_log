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
	
	static int N, K;
	static int[] A;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		K = nextInt();
		A = new int[N];
		for(int i=0;i<N;i++) A[i] = nextInt();
		
	}
	
	static void solve() throws Exception {
		
		int s = 0, e = 2000000, m = (s+e+1)>>1;
		while(s<e) {
			int cnt = 1, sum = 0;
			for(int i:A) {
				sum += i;
				if(sum >= m) {
					sum = 0;
					cnt++;
				}
			}
			if(cnt > K) s = m;
			else e = m-1;
			m = (s+e+1)>>1;
		}
		bw.write(m + "\n");
		
	}
	
}