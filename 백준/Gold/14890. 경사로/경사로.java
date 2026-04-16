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
	
	static int N, X;
    static int[][] A;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
    	X = nextInt();
    	A = new int[N][N];
    	for(int i=0;i<N;i++) for(int j=0;j<N;j++) A[i][j] = nextInt();
		
	}
	
	static void solve() throws Exception{
		
		int ans = 0;
        for(int i=0;i<N;i++) {
        	// 가로
        	{{{
        		boolean poss = true;
        		List<int[]> comp = new ArrayList<>();
        		int prev = A[i][0], cnt = 0;
        		for(int j=0;j<N;j++) {
        			if(prev == A[i][j]) cnt++;
        			else {
        				comp.add(new int[] {prev, cnt});
        				cnt = 1;
        				prev = A[i][j];
        			}
        		}
        		comp.add(new int[] {prev, cnt});
        		
        		for(int j=1;j<comp.size();j++) if(Math.abs(comp.get(j)[0] - comp.get(j-1)[0]) > 1) poss = false;
        		
        		for(int j=1;j<comp.size();j++) {
        			int left = comp.get(j-1)[0], right = comp.get(j)[0];
        			int leftcnt = comp.get(j-1)[1], rightcnt = comp.get(j)[1];
        			if(left < right) {
        				if(leftcnt < X) poss = false;
        			}
        			else {
        				if(rightcnt < X) poss = false;
        				comp.set(j, new int[] {right, rightcnt-X});
        			}
        		}
        		
        		ans += poss == true ? 1 : 0;
        	}}}
        	// 세로
        	{{{
        		boolean poss = true;
        		List<int[]> comp = new ArrayList<>();
        		int prev = A[0][i], cnt = 0;
        		for(int j=0;j<N;j++) {
        			if(prev == A[j][i]) cnt++;
        			else {
        				comp.add(new int[] {prev, cnt});
        				cnt = 1;
        				prev = A[j][i];
        			}
        		}
        		comp.add(new int[] {prev, cnt});
        		
        		for(int j=1;j<comp.size();j++) if(Math.abs(comp.get(j)[0] - comp.get(j-1)[0]) > 1) poss = false;
        		
        		for(int j=1;j<comp.size();j++) {
        			int left = comp.get(j-1)[0], right = comp.get(j)[0];
        			int leftcnt = comp.get(j-1)[1], rightcnt = comp.get(j)[1];
        			if(left < right) {
        				if(leftcnt < X) poss = false;
        			}
        			else {
        				if(rightcnt < X) poss = false;
        				comp.set(j, new int[] {right, rightcnt-X});
        			}
        		}
        		
        		ans += poss == true ? 1 : 0;
        	}}}
        }
        bw.write(ans + "\n");
		
	}
	
}