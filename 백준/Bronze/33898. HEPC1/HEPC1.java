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
	
	static String A;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		A = br.readLine();
		String temp = br.readLine();
		A += temp.charAt(1);
		A += temp.charAt(0);
		A += A.substring(0,3);
		
	}
	
	static void solve() throws Exception {
		
		for(int i=0;i<=3;i++) {
			if(A.substring(i,i+4).equals("HEPC") || A.substring(i,i+4).equals("CPEH")) {
				bw.write("YES");
				return;
			}
		}
		bw.write("NO");
		
	}
	
}