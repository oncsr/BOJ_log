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
	
	static int A, B, K;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		A = nextInt();
		B = nextInt();
		K = nextInt();
		
	}
	
	static void solve() throws Exception {
		
		List<Integer> ans = new ArrayList<>();
		ans.add(B);
		for(int i=A;ans.size()<K && i<B;i+=A) if(B%i == 0) ans.add(i);
		
		if(ans.size()<K || B%A!=0) {
			bw.write("-1");
			return;
		}
		for(int i:ans) bw.write(i + " ");
		
	}
	
}