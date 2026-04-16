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
	
	static int N, ans = 0;
	static int[][] res;
	static int[] ord;
	static int id = 0;
	static int roo = 0;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{

		N = Integer.parseInt(br.readLine());
		res = new int[9][N];
		for(int i=0;i<N;i++) {
			nextLine();
			for(int j=0;j<9;j++) res[j][i] = nextInt();
		}
		ord = new int[9];
		
	}
	
	static void solve() throws Exception{

		bck(0, 0);
		bw.write(ans + "\n");
		
	}
	
	static void bck(int cnt, int state) {
		if(cnt == 9) {
			if(ord[3] == 0) {
				id = 0;
				roo = 0;
				match(0,0,0);
			}
			return;
		}
		for(int i=0;i<9;i++) {
			if((state & (1<<i)) != 0) continue;
			ord[cnt] = i;
			bck(cnt+1, state | (1<<i));
			ord[cnt] = 0;
		}
	}
	
	static void match(int pos, int out, int score) {
		if(pos == N) {
			ans = Math.max(ans, score);
			return;
		}
		int batman = ord[id];
		int result = res[batman][pos];
		id = (id+1)%9;
		if(result == 0) {
			if(out == 2) {
				roo = 0;
				match(pos+1, 0, score);
			}
			else match(pos, out+1, score);
		}
		else {
			roo |= 1;
			for(int i=0;i<result;i++) {
				roo <<= 1;
				if((roo & 16) != 0) score++;
				roo %= 16;
			}
			match(pos, out, score);
		}
		
	}
	
}