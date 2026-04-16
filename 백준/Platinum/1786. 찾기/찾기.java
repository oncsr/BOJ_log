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
	
	static char[] T, P;
	static int[] X;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		T = br.readLine().toCharArray();
		P = br.readLine().toCharArray();
		X = new int[P.length];
		
	}
	
	static void solve() throws Exception{
		
		for(int i=1;i<P.length;i++) {
			X[i] = X[i-1];
			while(X[i]>0 && P[X[i]] != P[i]) X[i] = X[X[i]-1];
			if(P[X[i]] == P[i]) X[i]++;
		}
		
		List<Integer> res = new ArrayList<>();
		for(int i=0,j=0;i<T.length;i++) {
			while(j>0 && P[j] != T[i]) j = X[j-1];
			if(P[j] == T[i]) j++;
			if(j == P.length) {
				res.add(i-j+2);
				j = X[j-1];
			}
		}
		
		bw.write(res.size() + "\n");
		for(int i:res) bw.write(i + " ");
		
	}
	
}