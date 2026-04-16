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
	static long[] X, Y;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		X = new long[N];
		Y = new long[N];
		for(int i=0;i<N;i++) X[i] = nextInt();
		for(int i=0;i<N;i++) Y[i] = nextInt();
		
	}
	
	static void solve() throws Exception {
		
		long A = Y[0], B = X[0], G = gcd(A, B), c = 1, r = 1;
		A /= G;
		B /= G;
		for(int i=1;i<N;i++) {
			if(A*X[i] < B*Y[i]) {
				G = gcd(X[i], Y[i]);
				A = Y[i] / G;
				B = X[i] / G;
				r = 1;
				c = 1;
			}
			else if(A*X[i] == B*Y[i]) c = Math.max(c, ++r);
			else r = 0;
		}
		
		
		bw.write(A + " " + B + "\n" + c);
		
	}
	
	static long gcd(long a, long b) {
		if(a < b) {
			long t = a;
			a = b;
			b = t;
		}
		return a%b==0 ? b : gcd(b, a%b);
	}
	
}