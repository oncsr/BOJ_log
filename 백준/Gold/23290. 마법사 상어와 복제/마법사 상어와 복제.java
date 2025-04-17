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
	
	static final int INF = 1234567;
	static final int[] dx = {0,-1,-1,-1,0,1,1,1};
	static final int[] dy = {-1,-1,0,1,1,1,0,-1};
	static final int[] dShark = {2,0,6,4}; 

	// shark dir priority : up - left - down - right
	
	static int M, S;
	static List<Integer>[][] grid;
	static int[][] smell;
	static int sx, sy;
	
	static List<Integer>[][] copyList;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		M = nextInt();
		S = nextInt();
		grid = new List[4][4];
		smell = new int[4][4];
		for(int i=0;i<4;i++) for(int j=0;j<4;j++) {
			grid[i][j] = new ArrayList<>();
			smell[i][j] = INF;
		}
		
		for(int i=0;i<M;i++) {
			int x = nextInt()-1, y = nextInt()-1, d = nextInt()-1;
			grid[x][y].add(d);
		}
		sx = nextInt()-1;
		sy = nextInt()-1;
		
	}
	
	static void solve() throws Exception{
		
		while(S-->0) {
			
			copyStart();
			moveFish();
			moveShark();
			removeSmell();
			copyEnd();
			
			timeIncrease();
			
		}
		
		int cnt = 0;
		for(int i=0;i<4;i++) for(int j=0;j<4;j++) cnt += grid[i][j].size();
		bw.write(cnt + "\n");
		
	}
	
	static void copyStart() {
		copyList = new List[4][4];
		for(int i=0;i<4;i++) for(int j=0;j<4;j++) {
			copyList[i][j] = new ArrayList<>();
			for(int d:grid[i][j]) copyList[i][j].add(d);
		}
	}
	
	static void moveFish() {
		List<Integer>[][] resultGrid = new List[4][4];
		for(int i=0;i<4;i++) for(int j=0;j<4;j++) resultGrid[i][j] = new ArrayList<>();
		
		for(int i=0;i<4;i++) for(int j=0;j<4;j++) for(int d:grid[i][j]) {
			boolean canMove = false;
			for(int dir=d,k=0;k++<8;dir = (dir+7)%8) {
				int x = i+dx[dir], y = j+dy[dir];
				if(OOB(x,y)) continue;
				if(smell[x][y] != INF) continue;
				if(x==sx && y==sy) continue;
				canMove = true;
				resultGrid[x][y].add(dir);
				break;
			}
			if(!canMove) resultGrid[i][j].add(d);
		}
		
		grid = resultGrid;
	}
	
	static void moveShark() {
		int[][] vis = new int[4][4];
		
		int cnt = 0, max = -1;
		int resX = -1, resY = -1;
		int resXX = -1, resYY = -1;
		int resXXX = -1, resYYY = -1;
		for(int a=0;a<4;a++) {
			int x = sx+dx[dShark[a]], y = sy+dy[dShark[a]];
			if(OOB(x,y)) continue;
			
			cnt += vis[x][y]>0 ? 0 : grid[x][y].size();
			vis[x][y]++;
			
			for(int b=0;b<4;b++) {
				int xx = x+dx[dShark[b]], yy = y+dy[dShark[b]];
				if(OOB(xx,yy)) continue;
				
				cnt += vis[xx][yy]>0 ? 0 : grid[xx][yy].size();
				vis[xx][yy]++;
				
				for(int c=0;c<4;c++) {
					int xxx = xx+dx[dShark[c]], yyy = yy+dy[dShark[c]];
					if(OOB(xxx,yyy)) continue;
					
					cnt += vis[xxx][yyy]>0 ? 0 : grid[xxx][yyy].size();
					
					if(cnt > max) {
						max = cnt;
						resX = x;
						resY = y;
						resXX = xx;
						resYY = yy;
						resXXX = xxx;
						resYYY = yyy;
					}
					
					cnt -= vis[xxx][yyy]>0 ? 0 : grid[xxx][yyy].size();
					
				}
				
				vis[xx][yy]--;
				cnt -= vis[xx][yy]>0 ? 0 : grid[xx][yy].size();
				
			}
			
			vis[x][y]--;
			cnt -= vis[x][y]>0 ? 0 : grid[x][y].size();
		}
		
		if(!grid[resX][resY].isEmpty()) {
			grid[resX][resY] = new ArrayList<>();
			smell[resX][resY] = 2;
		}
		if(!grid[resXX][resYY].isEmpty()) {
			grid[resXX][resYY] = new ArrayList<>();
			smell[resXX][resYY] = 2;
		}
		if(!grid[resXXX][resYYY].isEmpty()) {
			grid[resXXX][resYYY] = new ArrayList<>();
			smell[resXXX][resYYY] = 2;
		}
		
		sx = resXXX;
		sy = resYYY;
	}
	
	static void removeSmell() {
		for(int i=0;i<4;i++) for(int j=0;j<4;j++) if(smell[i][j] == 0) smell[i][j] = INF;
	}
	
	static void copyEnd() {
		for(int i=0;i<4;i++) for(int j=0;j<4;j++) for(int d:copyList[i][j]) grid[i][j].add(d);
	}
	
	static void timeIncrease() {
		for(int i=0;i<4;i++) for(int j=0;j<4;j++) if(smell[i][j] != INF) smell[i][j]--;
	}
	
	static boolean OOB(int x, int y) {
		return x<0 || x>=4 || y<0 || y>=4;
	}
	
}