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
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
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

	static int[][] a = new int[4][18];
	static boolean possible;

	public static void main(String[] args) throws Exception {

		io = new IOController();

		init();
		solve();

		io.close();

	}

	static void init() throws Exception {

		for(int i=0;i<4;i++) for(int j=0;j<18;j++) a[i][j] = io.nextInt();

	}

	static void solve() throws Exception {

		for(int i=0;i<4;i++) io.write(check(i) + " ");

	}

	static int check(int i) {
		possible = false;
		int[] tmp = new int[18];
		bck(tmp,0,1, i);
		return possible ? 1 : 0;
	}

	static void bck(int[] temp, int x, int y, int z) {
		if(x == 6) {
			boolean res = true;
			for(int i=0;i<18;i++) res &= temp[i] == a[z][i];
			if(res) possible = true;
			return;
		}
		if(y == 6) {
			bck(temp,x+1,x+2,z);
			return;
		}

		for(int i=0;i<3;i++) {
			int j = 2-i;
			temp[x*3+i]++;
			temp[y*3+j]++;
			bck(temp,x,y+1,z);
			temp[x*3+i]--;
			temp[y*3+j]--;
		}
	}

}