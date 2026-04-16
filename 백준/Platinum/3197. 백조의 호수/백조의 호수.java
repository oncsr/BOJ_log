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
	
	static final int[] dx = {1,0,-1,0};
	static final int[] dy = {0,1,0,-1};
	
	static int R, C;
	static char[][] A;
	static int[][] T;
	static int sx = -1, sy = -1, ex = -1, ey = -1;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		R = nextInt();
		C = nextInt();
		A = new char[R][C];
		T = new int[R][C];
		for(int i=0;i<R;i++) for(int j=0;j<C;j++) T[i][j] = -1;
		for(int i=0;i<R;i++) A[i] = br.readLine().toCharArray();
		
	}
	
	static void solve() throws Exception{
		
		Queue<int[]> Q = new LinkedList<>();
		for(int i=0;i<R;i++) for(int j=0;j<C;j++) if(A[i][j] != 'X') {
			Q.offer(new int[] {i,j,0});
			T[i][j] = 0;
			if(A[i][j] == 'L') {
				if(sx == -1) {
					sx = i;
					sy = j;
				}
				else {
					ex = i;
					ey = j;
				}
			}
		}
		
		while(!Q.isEmpty()) {
			int[] now = Q.poll();
			int x = now[0], y = now[1], t = now[2];
			for(int i=0;i<4;i++) {
				int xx = x+dx[i], yy = y+dy[i];
				if(OOB(xx,yy)) continue;
				if(T[xx][yy] == -1) {
					T[xx][yy] = t+1;
					Q.offer(new int[] {xx,yy,t+1});
				}
			}
		}
		
		PriorityQueue<int[]> PQ = new PriorityQueue<>((a,b) -> a[2]-b[2]);
		boolean[][] vis = new boolean[R][C];
		vis[sx][sy] = true;
		PQ.offer(new int[] {sx,sy,0});
		while(!PQ.isEmpty()) {
			int[] now = PQ.poll();
			int x = now[0], y = now[1], t = now[2];
			
			if(x == ex && y == ey) {
				bw.write(t + "\n");
				return;
			}
			for(int i=0;i<4;i++) {
				int xx = x+dx[i], yy = y+dy[i];
				if(OOB(xx,yy) || vis[xx][yy]) continue;
				vis[xx][yy] = true;
				PQ.offer(new int[] {xx,yy,Math.max(T[xx][yy], t)});
			}
		}
		
	}
	
	static boolean OOB(int x, int y) {
		return x<0 || x>=R || y<0 || y>=C;
	}
	
}