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
	
	static int N, C, M;
	static int[] A;
	static List<Integer>[] Idx;
	static Random rd = new Random();
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		A = new int[N+1];
		Idx = new List[N+1];
		for(int i=1;i<=N;i++) Idx[i] = new ArrayList<>();
		
		for(int i=1;i<=N;i++) {
			A[i] = nextInt();
			Idx[A[i]].add(i);
		}
		
	}
	
	static void solve() throws Exception{

		for(;M-->0;) {
			int a = nextInt(), b = nextInt();
			
			int res = -1;
			for(int i=0;i<23;i++) {
				int x = A[a + rd.nextInt(b-a+1)];
				
				int cnt = lowerBound(x,b) - lowerBound(x,a-1);
				if(cnt > (b-a+1)/2) {
					res = x;
					break;
				}
				
			}
			if(res == -1) bw.write("0\n");
			else bw.write(res + "\n");
		}
		
	}
	
	static int lowerBound(int k, int x) {
		int s = 0, e = Idx[k].size(), m = (s+e)>>1;
		while(s<e) {
			if(Idx[k].get(m) <= x) s = m+1;
			else e = m;
			m = (s+e)>>1;
		}
		return m;
	}
	
}