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

	static int[] dx = {1,0,-1,0};
	static int[] dy = {0,1,0,-1};
	static int N, M;
	static int[][] A;
	static boolean[][] vis;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		nextLine();
		N = nextInt();
		M = nextInt();
		A = new int[N][M];
		vis = new boolean[N][M];
		for(int i=0;i<N;i++) {
			nextLine();
			for(int j=0;j<M;j++) A[i][j] = nextInt();
		}
		
	}
	
	static void solve() throws Exception{
		
		int ans = 0, cnt = 0;
		Deque<int[]> Q = new ArrayDeque<>();
		vis[0][0] = true;
		Q.offerLast(new int[] {0,0,0});
		while(!Q.isEmpty()) {
			int[] now = Q.pollFirst();
			int x = now[0], y = now[1], t = now[2];
			if(t > ans) {
				ans = t;
				cnt = 1;
			}
			else if(A[x][y] == 1) cnt++;
			
			for(int i=0;i<4;i++) {
				int xx = x+dx[i], yy = y+dy[i];
				if(xx<0 || xx>=N || yy<0 || yy>=M || vis[xx][yy]) continue;
				vis[xx][yy] = true;
				if(A[xx][yy] == 0) Q.offerFirst(new int[] {xx,yy,t});
				else Q.offerLast(new int[] {xx,yy,t+1});
			}
		}
		if(ans == 0) cnt = 0;
		bw.write(ans + "\n" + cnt);
		
	}
	
}