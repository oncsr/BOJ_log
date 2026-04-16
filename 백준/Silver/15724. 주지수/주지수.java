import java.util.*;
import java.io.*;


class Main {
	
	// IO field
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;

	static void nextLine() throws Exception {st = new StringTokenizer(br.readLine());}
	static int nextInt() {return Integer.parseInt(st.nextToken());}
	static long nextLong() {return Long.parseLong(st.nextToken());}
	static void bwEnd() throws Exception {bw.flush();bw.close();}
	
	// Additional field
	static int N, M;
	static int[][] A;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		nextLine();
		N = nextInt();
		M = nextInt();
		A = new int[N+1][M+1];
		for(int i=1;i<=N;i++){
		    nextLine();
		    for(int j=1;j<=M;j++) A[i][j] = nextInt() + A[i-1][j] + A[i][j-1] - A[i-1][j-1];
		}
		
	}
	
	static void solve() throws Exception{

		int Q = Integer.parseInt(br.readLine());
		while(Q-- > 0){
		    nextLine();
		    int x1 = nextInt(), y1 = nextInt(), x2 = nextInt(), y2 = nextInt();
		    bw.write((A[x2][y2] - A[x1-1][y2] - A[x2][y1-1] + A[x1-1][y1-1]) + "\n");
		}
		
	}
	
}