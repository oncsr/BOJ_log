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
	
	static int R, C;
	static char[][] A;
	
	static int[] dx = {1,0,-1,0};
	static int[] dy = {0,1,0,-1};
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		R = nextInt();
		C = nextInt();
		A = new char[R][];
		for(int i=0;i<R;i++) A[i] = br.readLine().toCharArray();
		
		
	}
	
	static void solve() throws Exception{
		
		Queue<int[]> Q = new LinkedList<>();
		boolean[][] vis = new boolean[R][C];
		for(int i=0;i<R;i++) for(int j=0;j<C;j++) if(A[i][j] == '*') {
			Q.offer(new int[] {i,j,0,-1});
			vis[i][j] = true;
		}
		for(int i=0;i<R;i++) for(int j=0;j<C;j++) if(A[i][j] == 'S') {
			Q.offer(new int[] {i,j,0,0});
			vis[i][j] = true;
		}
		
		while(!Q.isEmpty()) {
			int[] now = Q.poll();
			int x = now[0], y = now[1], t = now[2], p = now[3];
			if(A[x][y] == 'D') {
				bw.write(t + "\n");
				return;
			}
			for(int i=0;i<4;i++) {
				int xx = x+dx[i], yy = y+dy[i];
				if(xx<0 || xx>=R || yy<0 || yy>=C || vis[xx][yy] || A[xx][yy] == 'X') continue;
				if(p == -1 && A[xx][yy] == 'D') continue;
				vis[xx][yy] = true;
				Q.offer(new int[] {xx,yy,t+1,p});
			}
		}
		bw.write("KAKTUS");
		
	}
	
}