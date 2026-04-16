import java.util.*;
import java.io.*;

class IOController {
	BufferedReader br;
	BufferedWriter bw;
	StringTokenizer st;

	public IOController() {
		br = new BufferedReader(new InputStreamReader(System.in));
		bw = new BufferedWriter(new OutputStreamWriter(System.out));
		st = new StringTokenizer("");
	}

	String nextLine() throws Exception {
		String line = br.readLine();
		st = new StringTokenizer(line);
		return line;
	}

	String nextToken() throws Exception {
		while (!st.hasMoreTokens()) nextLine();
		return st.nextToken();
	}

	int nextInt() throws Exception {
		int res = 0;
		while(true) {
			try {
				res = Integer.parseInt(nextToken());
				break;
			} catch (Exception e) {}
		}
		return res;
	}

	long nextLong() throws Exception {
		long res = 0;
		while(true) {
			try {
				res = Long.parseLong(nextToken());
				break;
			} catch (Exception e) {}
		}
		return res;
	}

	double nextDouble() throws Exception {
		double res = 0;
		while(true) {
			try {
				res = Double.parseDouble(nextToken());
				break;
			} catch (Exception e) {}
		}
		return res;
	}

	void close() throws Exception {
		bw.flush();
		bw.close();
	}

	void write(String content) throws Exception {
		bw.write(content);
	}

}

public class Main {

	static IOController io;

	//

	static final int INF = (int)1e9 + 7;
	static final int[] dx = {-1,0,1,0};
	static final int[] dy = {0,1,0,-1};

	static int N, M;
	static char[][] a;
	static int[][] count;

	public static void main(String[] args) throws Exception {

		io = new IOController();

		init();
		solve();

		io.close();

	}

	static void init() throws Exception {

		N = io.nextInt();
		M = io.nextInt();
		a = new char[N][M];
		for(int i=0;i<N;i++) a[i] = io.nextLine().toCharArray();

	}

	static void solve() throws Exception {

		int x = io.nextInt()-1;
		int y = io.nextInt()-1;
		int ans = -1, dir = -1;
		char[] c = {'U','R','D','L'};
		for(int i=0;i<4;i++) {
			count = new int[N][M];
			int xx = x+dx[i], yy = y+dy[i], res = 0;
			if(blocked(xx,yy)) res = 1;
			else res = simulation(i,xx,yy,1);
			if(res > ans) {
				ans = res;
				dir = i;
			}
		}
		io.write(c[dir] + "\n" + (ans == INF ? "Voyager" : ans));

	}

	static int simulation(int dir, int x, int y, int cnt) {
		cnt++;
		if(++count[x][y] == 3) return INF;
		if(a[x][y] == '/') dir ^= 1;
		if(a[x][y] == '\\') dir ^= 3;
		x += dx[dir];
		y += dy[dir];
		if(blocked(x,y)) return cnt;
		return simulation(dir,x,y,cnt);
	}

	static boolean blocked(int x, int y) {return x<0 || y<0 || x>=N || y>=M || a[x][y]=='C';}

}