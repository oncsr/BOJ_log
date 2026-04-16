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
	
	static int N;
	static int[] A;
	static List<Integer> id1, id2;
	static int min = 100001, max = 0;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		A = new int[N];
		id1 = new ArrayList<>();
		id2 = new ArrayList<>();
		for(int i=0;i<N;i++) A[i] = nextInt();
		
	}
	
	static void solve() throws Exception{
		
		for(int i=0;i<N;i++) {
			min = Math.min(min, A[i]);
			max = Math.max(max, A[i]);
		}
		
		for(int i=0;i<N;i++) {
			if(A[i] == min) id1.add(i);
			if(A[i] == max) id2.add(i);
		}
		
		Collections.sort(id2);
		
		int ans = 1000001;
		for(int i:id1) {
			int p = lowerBound(i);
			if(p != id2.size()) ans = Math.min(ans, id2.get(p) - i + 1);
			if(p > 0) ans = Math.min(ans, i - id2.get(p-1) + 1);
		}
		bw.write(ans + "\n");
		
	}
	
	static int lowerBound(int x) {
		int s = 0, e = id2.size(), m = (s+e)>>1;
		while(s<e) {
			int v = id2.get(m);
			if(v < x) s = m+1;
			else e = m;
			m = (s+e)>>1;
		}
		return m;
	}
	
}