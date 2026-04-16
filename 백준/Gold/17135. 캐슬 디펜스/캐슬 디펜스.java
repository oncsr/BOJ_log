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

	static int N, M, D;
	static int[][] A;
	static int[] dx = {0,-1,0};
	static int[] dy = {-1,0,1};
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		nextLine();
		N = nextInt();
		M = nextInt();
		D = nextInt();
		A = new int[N][M];
		for(int i=0;i<N;i++) {
			nextLine();
			for(int j=0;j<M;j++) A[i][j] = nextInt();
		}
		
	}
	
	static void solve() throws Exception{
		
		int ans = 0;
		for(int a=0;a<M;a++) for(int b=a+1;b<M;b++) for(int c=b+1;c<M;c++) {
			ans = Math.max(ans, simulation(a,b,c));
		}
		bw.write(ans + "\n");
		
	}
	
	static int simulation(int x, int y, int z) {
		
		
		int[][] T = new int[N][M];
		for(int i=0;i<N;i++) for(int j=0;j<M;j++) T[i][j] = A[i][j];
		
		int res = 0;
		// (N+1,x)
		while(true) {
			int cnt = 0;
			for(int i=0;i<N;i++) for(int j=0;j<M;j++) if(T[i][j] != 0) cnt++;
			if(cnt == 0) return res;
			
			int[] a = find(T, x);
			int[] b = find(T, y);
			int[] c = find(T, z);
			
			if(a[0] != -1) {
				if(T[a[0]][a[1]] != 0) {
					res++;
					T[a[0]][a[1]] = 0;
				}
			}
			if(b[0] != -1) {
				if(T[b[0]][b[1]] != 0) {
					res++;
					T[b[0]][b[1]] = 0;
				}
			}
			if(c[0] != -1) {
				if(T[c[0]][c[1]] != 0) {
					res++;
					T[c[0]][c[1]] = 0;
				}
			}
			
			for(int i=N-1;i>0;i--) for(int j=0;j<M;j++) T[i][j] = T[i-1][j];
			for(int j=0;j<M;j++) T[0][j] = 0;
			
		}
		
	}
	
	static int[] find(int[][] T, int sy) {
		
		Queue<int[]> Q = new LinkedList<>();
		Q.offer(new int[] {N-1,sy,1});
		
		boolean[][] vis = new boolean[N][M];
		while(!Q.isEmpty()) {
			int[] now = Q.poll();
			int x = now[0], y = now[1], d = now[2];
			if(T[x][y] != 0) return new int[] {x,y};
			if(d == D) continue;
			for(int i=0;i<3;i++) {
				int xx = x+dx[i], yy = y+dy[i];
				if(xx<0 || xx>=N || yy<0 || yy>=M || vis[xx][yy]) continue;
				Q.offer(new int[] {xx,yy,d+1});
				vis[xx][yy] = true;
			}
		}
		return new int[] {-1,-1};
		
		
	}
	
}