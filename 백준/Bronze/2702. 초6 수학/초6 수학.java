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
	
	static int a,b;
	
	public static void main(String[] args) throws Exception {
		
		for(int T=nextInt();T-->0;solve()) ready();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		a = nextInt();
		b = nextInt();

	}
	
	static void solve() throws Exception{
		
		int g = gcd(a,b);
		bw.write((a*b/g) + " " + g + "\n");
		
	}
	
	static int gcd(int a, int b) {
		if(a<b) {
			a^=b;
			b^=a;
			a^=b;
		}
		return a%b==0 ? b : gcd(b,a%b);
	}
	
}