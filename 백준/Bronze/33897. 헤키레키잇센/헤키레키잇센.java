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
	static int[] A;
	static int ans = 0, res = 1;
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		A = new int[N];
		for(int i=0;i<N;i++) A[i] = nextInt();
		
	}
	
	static void solve() throws Exception{
		
		int cnt = 1;
		for(int i=1;i<N;i++){
		    if(A[i-1] <= A[i]) cnt++;
		    else{
		        ans++;
		        res = Math.max(res, cnt);
		        cnt = 1;
		    }
		}
		ans++;
		res = Math.max(res, cnt);
		bw.write(ans + " " + res);
		
	}
	
}
