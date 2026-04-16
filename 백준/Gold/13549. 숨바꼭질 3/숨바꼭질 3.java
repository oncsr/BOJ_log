import java.util.*;
import java.io.*;

class Main {
	
	// IO field
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;

	static void nextLine() throws Exception {st = new StringTokenizer(br.readLine());}
	static int nextInt() {return Integer.parseInt(st.nextToken());}
	static long nextLong() {return Long.parseLong(st.nextToken());}
	static void bwEnd() throws Exception {bw.flush();bw.close();}
	
	// Additional field
	static int N, K;
	static boolean[] vis;

	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
	}
	
	static void ready() throws Exception{
		
		nextLine();
		N = nextInt();
		K = nextInt();
		vis = new boolean[100001];
		
	}
	
	static void solve() throws Exception{
		
		vis[N] = true;
		Deque<int[]> D = new ArrayDeque<>();
		D.offer(new int[] {N,0});
		
		while(!D.isEmpty()) {
			
			int[] temp = D.poll();
			int x = temp[0], t = temp[1];
			
			if(x == K) {
				bw.write(t+"\n");
				return;
			}
			
			if(2*x <= 100000 && !vis[2*x]) {
				D.offerFirst(new int[] {2*x,t});
				vis[2*x] = true;
			}
			
			if(x > 0 && !vis[x-1]) {
				D.offerLast(new int[] {x-1,t+1});
				vis[x-1] = true;
			}
			if(x<100000 && !vis[x+1]) {
				D.offerLast(new int[] {x+1,t+1});
				vis[x+1] = true;
			}
			
		}
		
	}

}