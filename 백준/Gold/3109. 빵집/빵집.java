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

	static int R, C, ans = 0;
	static boolean[][] V;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{

		nextLine();
		R = nextInt();
		C = nextInt();
		V = new boolean[R][C];
		for(int i=0;i<R;i++) {
			char[] temp = br.readLine().toCharArray();
			for(int j=0;j<C;j++) if(temp[j] == 'x') V[i][j] = true;
		}
		
	}
	
	static void solve() throws Exception{

		for(int i=0;i<R;i++) {
			V[i][0] = true;
			if(dfs(i,0)) ans++;
		}
		bw.write(ans + "\n");
		
	}
	
	static boolean dfs(int x, int y) {
		if(y == C-1) return true;
		if(x>0 && !V[x-1][y+1]) {
			V[x-1][y+1] = true;
			if(dfs(x-1,y+1)) return true;
		}
		if(!V[x][y+1]) {
			V[x][y+1] = true;
			if(dfs(x,y+1)) return true;
		}
		if(x<R-1 && !V[x+1][y+1]) {
			V[x+1][y+1] = true;
			if(dfs(x+1,y+1)) return true;
		}
		return false;
	}
	
}