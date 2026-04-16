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
	
	static int N;
	static long M;
	static long[] A;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		A = new long[N];
		for(int i=0;i<N;i++) A[i] = nextInt();
		
	}
	
	static void solve() throws Exception {
		
		int cnt = 0;
		List<Long> T = new ArrayList<>();
		for(int i=0;i<N;i++) {
			if(A[i] == 0) {
				T.add(1L);
				cnt++;
			}
			else T.add(A[i]);
		}
		Collections.sort(T);
		
		long res = 0, sum = 0;
		for(int i=0;i<N;i++) {
			sum += T.get(i);
			res += (i+1)*T.get(i) - sum;
		}
		long ans = res;
		for(int i=0;i<cnt;i++) {
			res += (M+1)*N - 2*sum - M+1;
			ans = Math.max(ans, res);
			sum += M-1;
		}
		bw.write(ans + "\n");
		
	}
	
}