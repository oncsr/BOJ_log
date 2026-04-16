import java.awt.image.AreaAveragingScaleFilter;
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

class Point {
	int x,y;
	Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

public class Main {

	static IOController io;

	//

	static int N, M, L, K;
	static Point[] arr;

	public static void main(String[] args) throws Exception {

		io = new IOController();

		init();
		solve();

		io.close();

	}

	static void init() throws Exception {

		N = io.nextInt();
		M = io.nextInt();
		L = io.nextInt();
		K = io.nextInt();
		arr = new Point[K];
		for(int i=0;i<K;i++) arr[i] = new Point(io.nextInt(),io.nextInt());

	}

	static void solve() throws Exception {

		Arrays.sort(arr, (a,b) -> a.x==b.x ? a.y-b.y : a.x-b.x);
		int ans = 0;
		for(int i=0;i<K;i++) {
			int j = 0;
			while(j<K && arr[i].x + L >= arr[j].x) j++;
			List<Point> tmp = new ArrayList<>();
			for(int k=i;k<j;k++) tmp.add(arr[k]);
			Collections.sort(tmp, (a,b) -> a.y==b.y ? a.x-b.x : a.y-b.y);
			int cnt = 0;
			for(int s=0,e=0;e<tmp.size();s++) {
				while(e<tmp.size() && tmp.get(s).y + L >= tmp.get(e).y) e++;
				ans = Math.max(ans, e-s);
			}
		}
		io.write((K-ans) + "\n");

	}

}