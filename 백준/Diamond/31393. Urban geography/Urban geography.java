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

class DisjointSet {
	int[] root, rank;
	Stack<int[]> works;
	int components;

	DisjointSet(int size) {
		root = new int[size+1];
		rank = new int[size+1];
		works = new Stack<>();
		for(int i=1;i<=size;i++) {
			root[i] = i;
			rank[i] = 1;
		}
		components = size;
	}

	int find(int x) { return x == root[x] ? x : find(root[x]); }

	boolean union(int a, int b, int num) {
		int x = find(a), y = find(b);
		if(x == y) {
			works.push(new int[]{-1,-1,-1,-1});
			return false;
		}
		if(rank[x] > rank[y]) {
			int t = x;
			x = y;
			y = t;
		}
		works.push(new int[]{x,y,rank[x],num});
		rank[y] += rank[x];
		root[x] = y;
		components--;
		return true;
	}

	int rollback() {
		if(!works.isEmpty()) {
			int[] last = works.pop();
			int x = last[0], y = last[1], v = last[2], num = last[3];
			if(x == -1) return -1;
			rank[y] -= v;
			root[x] = x;
			components++;
			return num;
		}
		return -1;
	}

	boolean isConnectedAll() { return components == 1; }
}

public class Main {

	static IOController io;

	//

	static int N, M;
	static int[][] edges;
	static List<Integer>[] infos;
	static DisjointSet ds;
	static boolean[] exists;
	static List<Integer> ans;
	static List<Integer> lastAns;

	static void update(int s, int e, int l, int r, int n, int num) {
		if(l>r || l>e || r<s) return;
		if(l<=s && e<=r) {
			infos[n].add(num);
			return;
		}
		int m = (s+e)>>1;
		update(s,m,l,r,n*2,num);
		update(m+1,e,l,r,n*2+1,num);
	}

	static void clear(int s, int e, int n) {
		for(int num : infos[n]) {
			int a = edges[num][0], b = edges[num][1];
			if(ds.union(a,b,num)) {
				exists[num] = true;
			}
			if(ds.isConnectedAll() && ans.isEmpty()) {
				for(int i=0;i<M;i++) if(exists[i]) ans.add(edges[i][3]);
			}
		}
		if(s != e) {
			int m = (s+e)>>1;
			clear(s,m,n*2);
			clear(m+1,e,n*2+1);
		}
		for(int i=0;i<infos[n].size();i++) {
			int res = ds.rollback();
			if(res != -1) exists[res] = false;
		}
	}

	public static void main(String[] args) throws Exception {

		io = new IOController();

		N = io.nextInt();
		M = io.nextInt();
		edges = new int[M][];
		for(int i=0;i<M;i++) {
			int a = io.nextInt();
			int b = io.nextInt();
			int c = io.nextInt();
			edges[i] = new int[]{a,b,c,i+1};
		}
		Arrays.sort(edges, (a,b) -> a[2]-b[2]);

		int s = 0, e = (int)1e9 + 1, m = (s+e)>>1;
		while(s<e) {

			ds = new DisjointSet(N);
			exists = new boolean[M];
			infos = new List[4*M];
			ans = new ArrayList<>();
			for(int i=0;i<4*M;i++) infos[i] = new ArrayList<>();
			int st = 0;
			for(int ed=1;ed<M;ed++) {
				while(st<ed && edges[st][2] + m < edges[ed][2]) {
					update(0,M-1,st,ed-1,1,st);
					st++;
				}
			}
			while(st<M) {
				update(0,M-1,st,M-1,1,st++);
			}

			clear(0,M-1,1);

			if(ans.isEmpty()) s = m+1;
			else {
				e = m;
				lastAns = new ArrayList<>();
				lastAns.addAll(ans);
			}
			m = (s+e)>>1;

		}

		for(int i:lastAns) io.write(i + " ");

		io.close();

	}

}