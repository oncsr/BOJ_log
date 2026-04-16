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
	
	static int N, M, K;
	static char[][] A;
	static int sx, sy, ex, ey;
	
	static final int[] dx = {1,0,-1,0};
	static final int[] dy = {0,1,0,-1};
	static final int INF = (int)1e9 + 7;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		K = nextInt();
		A = new char[N][M];
		for(int i=0;i<N;i++) A[i] = br.readLine().toCharArray();
		sx = nextInt()-1;
		sy = nextInt()-1;
		ex = nextInt()-1;
		ey = nextInt()-1;

	}
	
	static void solve() throws Exception{
		
		Deque<int[]> Q = new ArrayDeque<>();
		int[][][] D = new int[N][M][4];
		for(int i=0;i<N;i++) for(int j=0;j<M;j++) Arrays.fill(D[i][j],INF);
		for(int i=0;i<4;i++) {
			D[sx][sy][i] = 0;
			Q.offer(new int[] {sx,sy,0,i,0});
		}
		
		while(!Q.isEmpty()) {
			int[] now = Q.pollFirst();
			int x = now[0], y = now[1], t = now[2], dir = now[3], rem = now[4];
			if(x==ex && y==ey) {
				bw.write(t + "\n");
				return;
			}
			for(int i=0;i<4;i++) {
				int xx = x+dx[i], yy = y+dy[i];
				if(xx<0 || xx>=N || yy<0 || yy>=M || A[xx][yy] == '#') continue;
				int cost = 1, newrem = K-1;
				if(i == dir && rem > 0) {
					cost = 0;
					newrem = rem-1;
				}
				if(D[xx][yy][i] > t+cost) {
					if(cost == 0) Q.offerFirst(new int[] {xx,yy,t+cost,i,newrem});
					else Q.offerLast(new int[] {xx,yy,t+cost,i,newrem});
					D[xx][yy][i] = t+cost;
				}
			}
		}
		bw.write("-1");
		
	}
	
}