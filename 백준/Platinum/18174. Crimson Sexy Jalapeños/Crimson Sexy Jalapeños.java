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
	
	static int R, C, K;
	static int a, b, c, d;
	static int TOP, BOTTOM, RIGHT, LEFT;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		R = nextInt();
		C = nextInt();
		K = nextInt();
		int top = R, bot = 1, right = 1, left = C;
		for(int i=0;i<K;i++) {
			int x = nextInt(), y = nextInt();
			top = Math.min(top, x);
			bot = Math.max(bot, x);
			right = Math.max(right, y);
			left = Math.min(left, y);
		}
		TOP = top-1;
		BOTTOM = R-bot;
		RIGHT = C-right;
		LEFT = left-1;

	}
	
	static void solve() throws Exception{
		
		while(true) {
			
			int xor = TOP ^ BOTTOM ^ RIGHT ^ LEFT;
			if(xor == 0) bw.write("pass\n");
			else {
				String dir = "";
				int k = -1;
				if(TOP != 0) {
					for(int i=0;i<TOP;i++) {
						if((i^BOTTOM^RIGHT^LEFT) == 0) {
							dir = "top";
							k = TOP-i;
							TOP -= k;
							break;
						}
					}
				}
				if(BOTTOM != 0) {
					for(int i=0;i<BOTTOM;i++) {
						if((TOP^i^RIGHT^LEFT) == 0) {
							dir = "bottom";
							k = BOTTOM-i;
							BOTTOM -= k;
							break;
						}
					}
				}
				if(RIGHT != 0) {
					for(int i=0;i<RIGHT;i++) {
						if((TOP^BOTTOM^i^LEFT) == 0) {
							dir = "right";
							k = RIGHT-i;
							RIGHT -= k;
							break;
						}
					}
				}
				if(LEFT != 0) {
					for(int i=0;i<LEFT;i++) {
						if((TOP^BOTTOM^RIGHT^i) == 0) {
							dir = "left";
							k = LEFT-i;
							LEFT -= k;
							break;
						}
					}
				}
				bw.write(dir + " " + k + "\n");
			}
			bw.flush();
			
			
			String input;
			input = nextToken();
			
			if(input.equals("yuck!")) return;
			
			int k = nextInt();
			if(input.equals("top")) {
				TOP -= k;
			}
			else if(input.equals("bottom")) {
				BOTTOM -= k;
			}
			else if(input.equals("right")) {
				RIGHT -= k;
			}
			else {
				LEFT -= k;
			}
		}
		
		
	}
	
}