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
	static List<Integer> L;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		L = new ArrayList<>();
		
	}
	
	static void solve() throws Exception{
		
		int max = 1;
		for(int i=0;i<N;i++){
		    int a = nextInt();
		    int p = lowerBound(a);
		    if(p == L.size()) L.add(a);
		    else L.set(p, a);
		    max = Math.max(max, L.size());
		}
		bw.write((N-max) + "\n");
		
	}
	
	static int lowerBound(int x){
	    int s = 0, e = L.size(), m = (s+e)>>1;
	    while(s<e){
	        int v = L.get(m);
	        if(v < x) s = m+1;
	        else e = m;
	        m = (s+e)>>1;
	    }
	    return m;
	}
	
}