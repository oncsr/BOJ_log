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
	
	static int N;
	static char[] A;
	static boolean[] vis;
	static char[] target = {'q','u','a','c','k'};
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		A = br.readLine().toCharArray();
		N = A.length;
		vis = new boolean[N];
		
	}
	
	static void solve() throws Exception{
		
		int ans = 0;
		while(true) {
			List<Integer> temp = new ArrayList<>();
			boolean find = false;
			int cur = 0;
			for(int idx=0;idx<N;idx++) if(!vis[idx]) {
				
				if(A[idx] == target[cur]) {
					cur++;
					temp.add(idx);
				}
				if(cur == 5) {
					for(int i:temp) vis[i] = true;
					find = true;
					temp = new ArrayList<>();
					cur = 0;
				}
				
			}
			if(!find) break;
			ans++;
		}
		for(int i=0;i<N;i++) if(!vis[i]) {
			bw.write("-1");
			return;
		}
		bw.write(ans + "\n");
		
	}
	
}