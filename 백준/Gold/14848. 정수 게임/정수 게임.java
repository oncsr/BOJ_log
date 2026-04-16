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
	
	static long N, K;
	static long[] A;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		K = nextInt();
		A = new long[(int)K];
		for(int i=0;i<K;i++) A[i] = nextInt();
		Arrays.sort(A);
		
	}
	
	static void solve() throws Exception{
		
		long rem = 0;
		for(int i=1;i<(1<<K);i++) {
			long cnt = 0, lcm = 1;
			for(int j=0;j<K;j++) if((i & (1<<j)) != 0) {
				cnt++;
				lcm = lcm(lcm, A[j]);
				if(lcm > N) break;
			}
			if(lcm == -1) continue;
			if(cnt % 2 == 0) rem -= N/lcm;
			else rem += N/lcm;
		}
		bw.write((N-rem) + "\n");
		
	}
	
	static long gcd(long a, long b) {
		if(a < b) {
			a^=b;
			b^=a;
			a^=b;
		}
		return a%b==0 ? b : gcd(b,a%b);
	}
	
	static long lcm(long a, long b) {
		return a*b/gcd(a,b);
	}
	
}