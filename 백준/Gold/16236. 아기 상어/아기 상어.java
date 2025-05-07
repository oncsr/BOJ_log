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
	
	static final int[] dx = {-1,0,0,1};
	static final int[] dy = {0,-1,1,0};
	
	static int N;
	static int[][] A;
	static int size = 2, eat = 0, x = -1, y = -1;
	static int time = 0;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		A = new int[N][N];
		for(int i=0;i<N;i++) for(int j=0;j<N;j++) {
			A[i][j] = nextInt();
			if(A[i][j] == 9) {
				x = i;
				y = j;
				A[i][j] = 0;
			}
		}
		
	}
	
	static void solve() throws Exception {
		
		while(true) {
			boolean[][] vis = new boolean[N][N];
			vis[x][y] = true;
			Queue<int[]> Q = new LinkedList<>();
			Q.offer(new int[] {x,y,0});
			int tarX = -1, tarY = -1, tarT = -1;
			while(!Q.isEmpty()) {
				int[] now = Q.poll();
				int xx = now[0], yy = now[1], t = now[2];
				if(A[xx][yy] != 0 && A[xx][yy] < size) {
					if(tarT == -1 || (tarT == t && (xx < tarX || (xx == tarX && yy < tarY)))) {
						tarX = xx;
						tarY = yy;
						tarT = t;
					}
				}
				for(int i=0;i<4;i++) {
					int xxx = xx+dx[i], yyy = yy+dy[i];
					if(Math.min(xxx, yyy)<0 || Math.max(xxx, yyy)>=N || vis[xxx][yyy] || A[xxx][yyy] > size) continue;
					vis[xxx][yyy] = true;
					Q.offer(new int[] {xxx,yyy,t+1});
				}
			}
			if(tarT == -1) break;
			time += tarT;
			x = tarX;
			y = tarY;
			if(++eat == size) {
				size++;
				eat = 0;
			}
			A[x][y] = 0;
		}
		bw.write(time + "\n");
		
	}
	
}