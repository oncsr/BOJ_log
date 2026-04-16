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
	
	static char[] A, B;
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		A = br.readLine().toCharArray();
		B = br.readLine().toCharArray();
		
	}
	
	static void solve() throws Exception{
		
		int[] C = new int[A.length];
		int cur = 0;
		for(int i=0;i<A.length;i++) {
		    cur += A[i] == '(' ? 1 : -1;
		    C[i] = cur;
		}
		
		int[] left = new int[A.length];
		left[0] = C[0];
		for(int i=1;i<A.length;i++) left[i] = Math.min(left[i-1], C[i]);
		
		int[] right = new int[A.length];
		right[A.length-1] = C[A.length-1];
		for(int i=A.length-2;i>=0;i--) right[i] = Math.min(right[i+1], C[i]);
		
		int minB = Integer.MAX_VALUE, lastB = 0;
		for(int i=0;i<B.length;i++){
		    lastB += B[i] == '(' ? 1 : -1;
		    minB = Math.min(minB, lastB);
		}
		
		if(C[A.length-1] + lastB != 0){
		    bw.write("0");
		    return;
		}
		for(int i=0;i<A.length-1;i++){
		    if(left[i] >= 0 && minB >= -C[i] && right[i+1] >= -lastB){
		        bw.write("1\n");
		        return;
		    }
		}
		bw.write("0\n");
		
	}
	
}
