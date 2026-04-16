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
	
	static int ChickenHouses = 0;
	static int Houses = 0;
	static int[][] ChickenHouse;
	static int[][] House;
	
	static int choosed = 0;
	static int ans = Integer.MAX_VALUE;
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		int[][] temp = new int[N][N];
		for(int i=0;i<N;i++) for(int j=0;j<N;j++) {
			temp[i][j] = nextInt();
			if(temp[i][j] == 1) Houses++;
			if(temp[i][j] == 2) ChickenHouses++; 
		}
		
		ChickenHouse = new int[ChickenHouses][2];
		House = new int[Houses][2];
		
		int idx1 = 0, idx2 = 0;
		for(int i=0;i<N;i++) for(int j=0;j<N;j++) {
			if(temp[i][j] == 1) House[idx1++] = new int[] {i,j};
			if(temp[i][j] == 2) ChickenHouse[idx2++] = new int[] {i,j};
		}
		
	}
	
	static void solve() throws Exception{
		
		bck(0,0);
		bw.write(ans + "\n");
		
	}
	
	static void bck(int cnt, int pos) {
		if(cnt == M) {
			ans = Math.min(ans, check());
			return;
		}
		for(int i=pos;i<ChickenHouses;i++) {
			choosed ^= (1<<i);
			bck(cnt+1, i+1);
			choosed ^= (1<<i);
		}
	}
	
	static int check() {
		
		int res = 0;
		for(int i=0;i<Houses;i++) {
			int min = Integer.MAX_VALUE;
			int hx = House[i][0], hy = House[i][1];
			for(int j=0;j<ChickenHouses;j++) if((choosed & (1<<j)) != 0) {
				int cx = ChickenHouse[j][0], cy = ChickenHouse[j][1];
				
				min = Math.min(min, Math.abs(hx-cx) + Math.abs(hy-cy));
			}
			res += min;
		}
		return res;
		
	}
	
}