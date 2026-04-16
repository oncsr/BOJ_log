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
	
	static int[] C = new int[6];
	static int[] N = new int[6];
	static int Q;
	static final int INF = (int)1e9;
	static int ans = 0;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		for(int i=2;i<=5;i++) C[i] = nextInt();
		for(int i=2;i<=5;i++) N[i] = nextInt();
		
	}
	
	static void solve() throws Exception{

		for(Q=nextInt();Q-->0;){
		    int o = nextInt(), x = nextInt();
		    if(o > 1) {
		        C[o] += x;
		        bw.write(C[o] + "\n");
		    }
		    else{
		        int c = INF;
		        for(int i=2;i<=5;i++) c = Math.min(c, C[i]/N[i]);
		        if(c < x) bw.write("Hello, siumii\n");
		        else{
		            ans += x;
		            bw.write(ans + "\n");
		            for(int i=2;i<=5;i++) C[i] -= x*N[i];
		        }
		    }
		}
		
	}
	
}