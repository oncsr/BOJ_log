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
	
	static int A, B, C, S = 0;
	static boolean[][] can;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		A = nextInt();
		B = nextInt();
		C = nextInt();
		
	}
	
	static void solve() throws Exception{

		can = new boolean[1501][1501];
		S = A+B+C;
		if(S%3 != 0) {
			bw.write("0\n");
			return;
		}
		int[] temp = new int[] {A,B,C};
		Arrays.sort(temp);
		can[temp[0]][temp[1]] = true;
		Queue<int[]> Q = new LinkedList<>();
		Q.offer(new int[] {temp[0],temp[1]});
		while(!Q.isEmpty()) {
			int[] now = Q.poll();
			int a = now[0], b = now[1], c = S-a-b;
			if(a == b && b == c) {
				bw.write("1\n");
				return;
			}
			if(a != b) {
				int aa = a+a, bb = b-a;
				temp = new int[] {aa,bb,c};
				Arrays.sort(temp);
				if(!can[temp[0]][temp[1]]) {
					can[temp[0]][temp[1]] = true;
					Q.offer(new int[] {temp[0],temp[1]});
				}
			}
			if(b != c) {
				int bb = b+b, cc = c-b;
				temp = new int[] {a,bb,cc};
				Arrays.sort(temp);
				if(!can[temp[0]][temp[1]]) {
					can[temp[0]][temp[1]] = true;
					Q.offer(new int[] {temp[0],temp[1]});
				}
			}
			if(a != c) {
				int aa = a+a, cc = c-a;
				temp = new int[] {aa,b,cc};
				Arrays.sort(temp);
				if(!can[temp[0]][temp[1]]) {
					can[temp[0]][temp[1]] = true;
					Q.offer(new int[] {temp[0],temp[1]});
				}
			}
		}
		bw.write("0\n");
		
	}
	
}