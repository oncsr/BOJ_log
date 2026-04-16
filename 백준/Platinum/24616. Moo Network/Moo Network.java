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

class Edge {
	long cost;
	int a, b;
	Edge(long cost, int a, int b) {
		this.cost = cost;
		this.a = a;
		this.b = b;
	}
}

public class Main {

	static IOController io;

	//

	static int N;
	static int[][] points;
	static TreeSet<int[]>[] height;
	static int[] r;

	static int f(int x) {return x==r[x] ? x : (r[x]=f(r[x]));}

	public static void main(String[] args) throws Exception {

		io = new IOController();

		init();
		solve();

		io.close();

	}

	static void init() throws Exception {

		N = io.nextInt();
		points = new int[N][];
		height = new TreeSet[11];
		r = new int[N];
		for(int i=0;i<=10;i++) height[i] = new TreeSet<>((a,b) -> a[0]==b[0] ? a[1]-b[1] : a[0]-b[0]);
		for(int i=0;i<N;i++) {
			r[i] = i;
			points[i] = new int[]{io.nextInt(),io.nextInt(),i};
			height[points[i][1]].add(new int[]{points[i][0], i});
		}

	}

	static void solve() throws Exception {

		List<Edge> list = new ArrayList<>();
		for(int[] point : points) {
			int x = point[0], y = point[1], z = point[2];
			for(int i=0;i<=10;i++) {
				{
					int[] right = height[i].ceiling(new int[]{x,-1});
					if(right != null) {
						long xx = right[0], yy = i;
						int zz = right[1];
						list.add(new Edge((xx-x)*(xx-x) + (yy-y)*(yy-y), z, zz));
					}
				}
				{
					int[] left = height[i].lower(new int[]{x,-1});
					if(left != null) {
						long xx = left[0], yy = i;
						int zz = left[1];
						list.add(new Edge((xx-x)*(xx-x) + (yy-y)*(yy-y), z, zz));
					}
				}
			}
		}

		Collections.sort(list, (a,b) -> Long.compare(a.cost,b.cost));
		long ans = 0;
		for(Edge edge : list) {
			long cost = edge.cost;
			int a = edge.a, b = edge.b;
			int x = f(a), y = f(b);
			if(x == y) continue;
			r[x] = y;
			ans += cost;
		}

		io.write(ans + "\n");

	}

}