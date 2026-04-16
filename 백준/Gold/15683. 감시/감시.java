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
	
	static int N, M;
	static int[][] A;
	static int[][] see;
	static int ans = 1234567890;
	
	static int[] dx = {-1,0,1,0};
	static int[] dy = {0,1,0,-1};
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		A = new int[N][M];
		for(int i=0;i<N;i++) for(int j=0;j<M;j++) A[i][j] = nextInt();
		see = new int[N][M];
		
	}
	
	static void solve() throws Exception{

		recur(0,0);
		bw.write(ans + "\n");
		
	}
	
	static void recur(int x, int y) throws Exception {
		if(y == M) {
			y = 0;
			x++;
		}
		if(x == N) {
			int res = 0;
			for(int i=0;i<N;i++) for(int j=0;j<M;j++) if(A[i][j] == 0 && see[i][j] == 0) res++;
			ans = Math.min(ans, res);
			return;
		}
		
		if(A[x][y] == 6 || A[x][y] == 0) recur(x,y+1);
		else {
			int type = A[x][y];
			for(int i=0;i<4;i++) {
				change(x,y,i,1);
				if(type >= 3) change(x,y,(i+1)%4,1);
				if(type == 2 || type == 5) change(x,y,(i+2)%4,1);
				if(type >= 4) change(x,y,(i+3)%4,1);
				
				recur(x,y+1);
				
				change(x,y,i,-1);
				if(type >= 3) change(x,y,(i+1)%4,-1);
				if(type == 2 || type == 5) change(x,y,(i+2)%4,-1);
				if(type >= 4) change(x,y,(i+3)%4,-1);
			}
		}
		
	}
	
	static void change(int x, int y, int dir, int val) {
		while(true) {
			x += dx[dir];
			y += dy[dir];
			if(x<0 || x>=N || y<0 || y>=M || A[x][y] == 6) break;
			see[x][y] += val;
		}
	}
	
}