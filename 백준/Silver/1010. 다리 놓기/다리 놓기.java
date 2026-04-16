import java.util.*;
import java.io.*;
import java.math.BigInteger;

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
	
	static long N, M;
	
	public static void main(String[] args) throws Exception {
		
		for(int TC = nextInt(); TC-->0;) {
			
			ready();
			solve();
		}
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		
	}
	
	static void solve() throws Exception{
		
		BigInteger res = new BigInteger("1");
		
		for(int i=1;i<=M;i++) res = res.multiply(new BigInteger(Integer.toString(i)));
		for(int i=1;i<=N;i++) res = res.divide(new BigInteger(Integer.toString(i)));
		for(int i=1;i<=M-N;i++) res = res.divide(new BigInteger(Integer.toString(i)));
		
		bw.write(res + "\n");
		
	}
	
}