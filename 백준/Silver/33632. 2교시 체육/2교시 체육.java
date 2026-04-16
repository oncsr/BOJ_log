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
	
	static int H, W;
	static int x, y;
	static int px, py, qx, qy;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		W = nextInt();
		H = nextInt();
		x = nextInt();
		y = nextInt();
		px = nextInt();
	    py = nextInt();
		qx = nextInt();
		qy = nextInt();
		
	}
	
	static void solve() throws Exception{

		if(y < py) {
		    bw.write("0.0\n");
		    return;
		}
		double dx = x-px;
		double dy = y-py;
		double x1 = Math.min((double)W, Math.max(0.0, (double)px - (double)py/dy * dx));
		
		dx = x-qx;
		double x2 = Math.max(0.0, Math.min((double)W, (double)qx - (double)py/dy *dx));
		
		bw.write((x2-x1)/W + "\n");
		
	}
	
}