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
	
	static char[] S;
	static boolean[] E;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		S = br.readLine().toCharArray();
		E = new boolean[S.length];
		
	}
	
	static void solve() throws Exception {
		
		int zeros = 0, ones = 0;
		for(int i=0;i<S.length;i++) {
			zeros += S[i] == '0' ? 1 : 0;
			ones += S[i] == '1' ? 1 : 0;
		}
		
		ones >>= 1;
		for(int i=0;i<S.length;i++) {
			if(ones>0 && S[i] == '1') {
				E[i] = true;
				ones--;
			}
		}
		
		zeros >>= 1;
		for(int i=S.length-1;i>=0;i--) {
			if(zeros>0 && S[i] == '0') {
				E[i] = true;
				zeros--;
			}
		}
		
		for(int i=0;i<S.length;i++) if(!E[i]) bw.write(S[i]);
		
	}
	
}