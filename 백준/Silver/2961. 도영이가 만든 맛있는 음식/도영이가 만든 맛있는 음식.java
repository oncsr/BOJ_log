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
	static int[] S, B;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{

		N = Integer.parseInt(br.readLine());
		S = new int[N];
		B = new int[N];
		for(int i=0;i<N;i++) {
			nextLine();
			S[i] = nextInt();
			B[i] = nextInt();
		}
		
	}
	
	static void solve() throws Exception{

		int ans = (int)2e9;
		for(int i=1;i<(1<<N);i++) {
			int s = 1, b = 0;
			for(int j=0;j<N;j++) if((i & (1<<j)) != 0) {
				s *= S[j];
				b += B[j];
			}
			ans = Math.min(ans, Math.abs(s-b));
		}
		bw.write(ans+"\n");
		
	}
	
}