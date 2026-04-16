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
	
	static final int[] dx = {1,0,-1,0};
	static final int[] dy = {0,1,0,-1};

	static int N;
	static int[][] A;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		A = new int[N][N];
		for(int i=0;i<N;i++) for(int j=0;j<N;j++) A[i][j] = nextInt();
		
	}
	
	static void solve() throws Exception {
		
		boolean[][][][] vis = new boolean[N][N][16][4];
		Queue<int[]> Q = new LinkedList<>();
		vis[0][0][0][0] = true;
		vis[0][0][0][1] = true;
		Q.offer(new int[] {0,0,0,0,0});
		Q.offer(new int[] {0,0,0,1,0});
		while(!Q.isEmpty()) {
			int[] now = Q.poll();
			int x = now[0], y = now[1], a = now[2], d = now[3], t = now[4];
			
			if(x==N-1 && y==N-1) {
				bw.write(t + "\n");
				return;
			}
			for(int i=0;i<4;i++) {
				int aa = i==d ? a+1 : 1;
				int xx = x+dx[i]*aa, yy = y+dy[i]*aa;
				if(xx<0 || xx>=N || yy<0 || yy>=N || vis[xx][yy][aa][i] || (A[xx][yy] != 0 && t+1 >= A[xx][yy])) continue;
				int xxx = x+dx[i], yyy = y+dy[i];
				boolean blocked = false;
				while(xxx!=xx || yyy!=yy) {
					if(A[xxx][yyy] > 0 && t >= A[xxx][yyy]) {
						blocked = true;
						break;
					}
					xxx += dx[i];
					yyy += dy[i];
				}
				if(blocked) continue;
				vis[xx][yy][aa][i] = true;
				Q.offer(new int[] {xx,yy,aa,i,t+1});
			}
		}
		bw.write("Fired");
		
	}
	
}