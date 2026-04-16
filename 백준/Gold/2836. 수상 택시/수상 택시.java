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

	static int N, M;
	static List<int[]> list;

	public static void main(String[] args) throws Exception {

		io = new IOController();

		init();
		solve();

		io.close();

	}

	static void init() throws Exception {

		N = io.nextInt();
		M = io.nextInt();
		list = new ArrayList<>();
		for(int i=0;i<N;i++) {
			int s = io.nextInt(), e = io.nextInt();
			if(e < s) {
				list.add(new int[]{e,0});
				list.add(new int[]{s,1});
			}
		}

	}

	static void solve() throws Exception {

		Collections.sort(list, (a,b) -> a[0]==b[0] ? a[1]-b[1] : a[0]-b[0]);
		long ans = M, last = -1, cnt = 0;
		for(int i=0;i<list.size();) {
			int cur = list.get(i)[0];
			while(i<list.size() && list.get(i)[0] == cur) {
				if(list.get(i)[1] == 0) {
					if(++cnt == 1) last = cur;
				}
				else cnt--;
				i++;
			}
			if(cnt == 0) ans += (cur-last)*2;
		}

		io.write(ans + "\n");

	}

}