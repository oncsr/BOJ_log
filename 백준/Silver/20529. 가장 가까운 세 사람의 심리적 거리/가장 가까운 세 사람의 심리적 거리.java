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
	
	static char[] base = {'I','S','F','P'};
	static int[] cnt = new int[16];
	static int N;
	
	public static void main(String[] args) throws Exception {
		
		for(int T=nextInt();T-->0;solve()) ready();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		cnt = new int[16];
		N = nextInt();
		for(int i=0;i<N;i++) {
			char[] temp = nextToken().toCharArray();
			int res = 0;
			for(int j=0;j<4;j++) res |= base[j] == temp[j] ? (1<<j) : 0;
			cnt[res]++;
		}

	}
	
	static void solve() throws Exception{
		
		int ans = 12345;
		for(int a=0;a<16;a++) if(cnt[a] > 0) {
			cnt[a]--;
			for(int b=0;b<16;b++) if(cnt[b] > 0) {
				cnt[b]--;
				for(int c=0;c<16;c++) if(cnt[c] > 0) {
					ans = Math.min(ans, dist(a,b) + dist(b,c) + dist(a,c));
				}
				cnt[b]++;
			}
			cnt[a]++;
		}
		bw.write(ans + "\n");
		
	}
	
	static int dist(int a, int b) {
		int res = 0;
		for(int i=0;i<4;i++) {
			if((((1<<i)&a) ^ ((1<<i)&b)) != 0) res++;
		}
		return res;
	}
	
}