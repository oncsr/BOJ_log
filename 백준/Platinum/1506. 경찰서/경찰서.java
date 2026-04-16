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

	static int N;
	static int[] cost;
	static boolean[][] can;

	public static void main(String[] args) throws Exception {

		io = new IOController();

		N = io.nextInt();
		cost = new int[N];
		for(int i=0;i<N;i++) cost[i] = io.nextInt();
		can = new boolean[N][N];
		for(int i=0;i<N;i++) {
			char[] tmp = io.nextToken().toCharArray();
			for(int j=0;j<N;j++) can[i][j] = tmp[j] == '1';
			can[i][i] = true;
		}

		for(int i=0;i<N;i++) for(int j=0;j<N;j++) for(int k=0;k<N;k++) can[j][k] = can[j][k] | (can[j][i] & can[i][k]);

		boolean[] vis = new boolean[N];
		int ans = 0;
		for(int i=0;i<N;i++) if(!vis[i]) {
			int min = Integer.MAX_VALUE;
			for(int j=0;j<N;j++) if(!vis[j] && can[i][j] && can[j][i]) {
				vis[j] = true;
				min = Math.min(min, cost[j]);
			}
			ans += min;
		}
		io.write(ans + "\n");

		io.close();

	}

}