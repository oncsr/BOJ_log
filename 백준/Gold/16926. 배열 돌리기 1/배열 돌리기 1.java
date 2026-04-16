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

	static int N, M, R;
	static int[][] A;
	static int[] dx = {0,1,0,-1};
	static int[] dy = {1,0,-1,0};
	
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{

		nextLine();
		N = nextInt();
		M = nextInt();
		R = nextInt();
		A = new int[N][M];
		for(int i=0;i<N;i++) {
			nextLine();
			for(int j=0;j<M;j++) A[i][j] = nextInt();
		}
		
	}
	
	static void solve() throws Exception{

		while(R-- > 0) rotate();
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) bw.write(A[i][j] + " ");
			bw.write("\n");
		}
		
	}
	
	static void rotate() {
		
		int x = 0, y = 0;
		while(x<N-1-x && y<M-1-y) {
			
			int temp = A[x][y];
			int dir = 0;
			int xx = x, yy = y;
			while(true) {
				int nx = xx+dx[dir];
				int ny = yy+dy[dir];
				if(nx<x || nx>N-1-x || ny<y || ny>M-1-y) {
					dir = (dir+1)%4;
					nx = xx+dx[dir];
					ny = yy+dy[dir];
				}
				if(nx==x && ny==y) {
					A[xx][yy] = temp;
					break;
				}
				else A[xx][yy] = A[nx][ny];
				xx = nx;
				yy = ny;
			}
			x++;
			y++;
			
		}
		
	}
	
}