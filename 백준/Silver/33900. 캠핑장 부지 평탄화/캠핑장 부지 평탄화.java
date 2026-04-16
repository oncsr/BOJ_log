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
	
	static int N, M, R, C;
	static int[][] A, B;
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		R = nextInt();
		C = nextInt();
		A = new int[N][M];
		for(int i=0;i<N;i++) for(int j=0;j<M;j++) A[i][j] = nextInt();
		B = new int[R][C];
		for(int i=0;i<R;i++) for(int j=0;j<C;j++) B[i][j] = nextInt();
		
	}
	
	static void solve() throws Exception{
		
		int ans = 0;
		for(int i=0;i<=N-R;i++) for(int j=0;j<=M-C;j++){
		    HashSet<Integer> S = new HashSet<>();
		    for(int x=i;x<i+R;x++) for(int y=j;y<j+C;y++) S.add(A[x][y] - B[x-i][y-j]);
		    ans += S.size() == 1 ? 1 : 0;
		}
		bw.write(ans + "\n");
		
	}
	
}
