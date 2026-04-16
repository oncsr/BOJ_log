import java.util.*;
import java.io.*;

public class Main {
	
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
	
	static int N, A, B, C, da, db, dc;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		A = nextInt();
		B = nextInt();
		C = nextInt();
		da = nextInt();
		db = nextInt();
		dc = nextInt();
		
	}
	
	static void solve() throws Exception {
		
		int[][] vis = new int[2*N][2*N];
		vis[A][B] = -1;
		Queue<int[]> Q = new LinkedList<>();
		Q.offer(new int[] {A,B});
		while(!Q.isEmpty()) {
			int[] now = Q.poll();
			int a = now[0], b = now[1];
			if(a == N && b == N) {
				
				Stack<Character> st = new Stack<>();
				while(vis[a][b] != -1) {
					int op = vis[a][b];
					if(op == 1) {
						st.push('A');
						a -= da;
					}
					if(op == 2) {
						st.push('B');
						a += db;
						b -= db;
					}
					if(op == 3) {
						st.push('C');
						b += dc;
					}
				}
				bw.write(st.size() + "\n");
				while(!st.isEmpty()) bw.write(st.pop());
				return;
			}
			
			if(a+da < 2*N && vis[a+da][b] == 0 && a+da+b > N && a+da+b < 3*N) {
				vis[a+da][b] = 1;
				Q.offer(new int[] {a+da,b});
			}
			
			if(b+db < 2*N && a-db > 0 && vis[a-db][b+db] == 0 && a+b > N && a+b < 3*N){
				vis[a-db][b+db] = 2;
				Q.offer(new int[] {a-db,b+db});
			}
			
			if(b-dc > 0 && vis[a][b-dc] == 0 && a+b-dc > N && a+b-dc < 3*N) {
				vis[a][b-dc] = 3;
				Q.offer(new int[] {a,b-dc});
			}
			
		}
		bw.write("-1");
		
	}
	
}