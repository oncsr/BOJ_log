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
	
	static int[] dx = {1,0,-1,0};
	static int[] dy = {0,1,0,-1};
	
	static int num = 0;
	static int[] r;
	
	static int f(int x) {return x==r[x] ? x : (r[x]=f(r[x]));}
	
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
		
	}
	
	static void solve() throws Exception{
		
		// Island Numbering (with BFS)
		boolean[][] vis = new boolean[N][M];
		for(int i=0;i<N;i++) for(int j=0;j<M;j++) if(A[i][j] == 1 && !vis[i][j]) {
			num++;
			Queue<int[]> Q = new LinkedList<>();
			vis[i][j] = true;
			Q.offer(new int[] {i,j});
			while(!Q.isEmpty()) {
				int[] now = Q.poll();
				int x = now[0], y = now[1];
				A[x][y] = num;
				for(int k=0;k<4;k++) {
					int xx = x+dx[k], yy = y+dy[k];
					if(xx<0 || xx>=N || yy<0 || yy>=M || vis[xx][yy] || A[xx][yy] != 1) continue;
					vis[xx][yy] = true;
					Q.offer(new int[] {xx,yy});
				}
			}
		}
		
		// Find Edges
		r = new int[num+1];
		for(int i=1;i<=num;i++) r[i] = i;
		List<int[]> E = new ArrayList<>();
		
		for(int i=0;i<N;i++) for(int j=0;j<M;j++) if(A[i][j] != 0) {
			for(int k=0;k<4;k++) {
				int x = i+dx[k], y = j+dy[k], cost = 0;
				while(0<=x&&x<N && 0<=y&&y<M) {
					if(A[x][y] == 0) {
						cost++;
						x += dx[k];
						y += dy[k];
						continue;
					}
					if(A[x][y] != A[i][j] && cost > 1) E.add(new int[] {A[i][j], A[x][y], cost});
					break;
				}
				
			}
		}
		
		// Find MST
		Collections.sort(E, (a,b) -> a[2]-b[2]);
		int mst = 0, con = 0;
		for(int[] e:E) {
			int a = e[0], b = e[1], c = e[2];
			int x = f(a), y = f(b);
			if(x == y) continue;
			con++;
			mst += c;
			r[x] = y;
		}
		
		bw.write((con==num-1 ? mst : -1) + "\n");
		
	}
	
}