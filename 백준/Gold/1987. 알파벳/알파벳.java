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
	
	static int R, C;
	static int[][] A;
	static int ans = 0;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		nextLine();
		R = nextInt();
		C = nextInt();
		
		A = new int[R][C];
		
		for(int i=0;i<R;i++) {
			char[] temp = br.readLine().toCharArray();
			for(int j=0;j<C;j++) A[i][j] = temp[j] - 'A';
		}
		
	}
	
	static void solve() throws Exception{
		
		dfs(0,0,1,(1<<A[0][0]));
		bw.write(ans + "\n");
		
	}
	
	static void dfs(int x, int y, int cnt, int vis) {
		
		ans = Math.max(ans, cnt);
		for(int i=0;i<4;i++) {
			int xx = x+dx[i], yy = y+dy[i];
			if(xx<0 || xx>=R || yy<0 || yy>=C || ((vis & (1<<A[xx][yy])) != 0)) continue;
			dfs(xx,yy,cnt+1,vis | (1<<A[xx][yy]));
		}
		
	}
	
}