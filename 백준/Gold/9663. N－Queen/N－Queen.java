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
	
	static int N, ans = 0;
	static int[][] B;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		B = new int[N][N];
		
	}
	
	static void solve() throws Exception {
		
		for(int i=0;i<N;i++) bck(0,i);
		bw.write((ans/N) + "\n");
		
	}
	
	static void bck(int x, int y) {
		if(x == N) {
			ans++;
			return;
		}
		if(B[x][y] != 0) return;
		for(int i=x+1;i<N;i++) {
			B[i][y]++;
			if(y-(i-x) >= 0) B[i][y-(i-x)]++;
			if(y+(i-x) < N) B[i][y+(i-x)]++;
		}
		for(int j=0;j<N;j++) bck(x+1,j);
		for(int i=x+1;i<N;i++) {
			B[i][y]--;
			if(y-(i-x) >= 0) B[i][y-(i-x)]--;
			if(y+(i-x) < N) B[i][y+(i-x)]--;
		}
	}
	
}