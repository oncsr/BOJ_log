import java.io.*;
import java.util.*;

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
		while (!st.hasMoreTokens())
			nextLine();
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

	static int N, L;
	static int[][] arr;

	public static void main(String[] args) throws Exception {

		io = new IOController();

		N = io.nextInt();
		L = io.nextInt();
		arr = new int[N][];
		for(int i=0;i<N;i++) arr[i] = new int[]{io.nextInt(),io.nextInt()};

		Arrays.sort(arr, (a,b) -> a[0]==b[0] ? a[1]-b[1] : a[0]-b[0]);

		int cnt = 0, prev = -1;
		for(int[] oasis : arr) {
			int s = oasis[0], e = oasis[1];
			s = Math.max(s, prev);
			if(s >= e) continue;
			int len = e-s;
			int need = (len-1)/L + 1;
			cnt += need;
			prev = s + need*L;
		}
		io.write(cnt + "\n");

		io.close();

	}

}