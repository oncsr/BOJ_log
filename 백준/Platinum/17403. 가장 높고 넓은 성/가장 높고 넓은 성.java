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
	
	static class Point{
		int x, y, id;
		Point(int x, int y, int id){
			this.x = x;
			this.y = y;
			this.id = id;
		}
		
		// a -> b -> this
		// positive : counter-clockwise
		int ccw(Point a, Point b) {
			int res = a.x * b.y + b.x * this.y + this.x * a.y - (b.x * a.y + this.x * b.y + a.x * this.y);
			if(res > 0) return 1;
			if(res < 0) return -1;
			return 0;
		}
	}
	static int N;
	static List<Point> A;
	static int[] ans;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		A = new ArrayList<>();
		ans = new int[N];
		for(int i=0;i<N;i++) A.add(new Point(nextInt(), nextInt(), i));
		
	}
	
	static void solve() throws Exception{
		
		Collections.sort(A, (a,b) -> a.x==b.x ? a.y-b.y : a.x-b.x);
		
		for(int floor=1;;floor++) {
			List<Point> upper = new ArrayList<>();
			List<Point> lower = new ArrayList<>();
			
			for(Point p:A) if(ans[p.id] == 0) {
				while(ans[p.id]==0 && upper.size()>=2 && p.ccw(upper.get(upper.size()-2), upper.get(upper.size()-1)) >= 0) upper.remove(upper.size()-1);
				upper.add(p);
				while(ans[p.id]==0 && lower.size()>=2 && p.ccw(lower.get(lower.size()-2), lower.get(lower.size()-1)) <= 0) lower.remove(lower.size()-1);
				lower.add(p);
			}
			
			List<Point> convexHull = new ArrayList<>();
			for(int i=0;i<lower.size()-1;i++) convexHull.add(lower.get(i));
			for(int i=upper.size()-1;i>0;i--) convexHull.add(upper.get(i));
			
			if(convexHull.size() < 3) break;
			
			for(Point p:convexHull) if(ans[p.id]==0) ans[p.id] = floor;
		}
		
		for(int i=0;i<N;i++) bw.write(ans[i] + " ");
		
		
		
	}
	
}