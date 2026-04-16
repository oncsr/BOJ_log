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
	
	static int[] L = new int[986409];
	static int idx = 0;
	
	static int[] choose = new int[9];
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		perm(0,0);
		Arrays.sort(L);
		
	}
	
	static void solve() throws Exception{
		
		String line;
		while((line = br.readLine()) != null) {
			int N = Integer.parseInt(line);
			int x = upperBound(N);
			if(x == 986409) bw.write("0\n");
			else bw.write(L[x] + "\n");
		}
		
	}
	
	static void perm(int cnt, int state) {
		if(cnt > 0) {
			int g = 1, res = 0;
			for(int i=0;i<cnt;i++) {
				res += g*choose[i];
				g *= 10;
			}
			L[idx++] = res;
		}
		if(cnt == 9) return;
		for(int i=1;i<10;i++) if((state & (1<<i)) == 0) {
			choose[cnt] = i;
			perm(cnt+1, state | (1<<i));
			choose[cnt] = 0;
		}
	}
	
	static int upperBound(int x) {
		int s = 0, e = 986409, m = (s+e)>>1;
		while(s<e) {
			if(L[m] <= x) s = m+1;
			else e = m;
			m = (s+e)>>1;
		}
		return m;
	}
	
}