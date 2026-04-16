import java.util.*;
import java.io.*;


class Main {
	
	// IO field
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st = new StringTokenizer("");

	static void nextLine() throws Exception {st = new StringTokenizer(br.readLine());}
	static int nextInt() throws Exception {
		if(!st.hasMoreTokens()) nextLine();
		return Integer.parseInt(st.nextToken());
	}
	static long nextLong() {return Long.parseLong(st.nextToken());}
	static void bwEnd() throws Exception {bw.flush();bw.close();}
	
	// Additional field
	
	static int N;
	static int[] C;
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		C = new int[N];
		for(int i=0;i<N;i++) C[i] = nextInt();
		
	}
	
	static void solve() throws Exception{
		
		int ans = 0;
		for(int x=1;x<(1<<N);x++) {
			long a = 0, b = 1;
			for(int i=0;i<N;i++) if((x&(1<<i)) != 0) {
				// a/b + 1/C[i] = (a*C[i] + b) / b*C[i]
				a = (a*C[i] + b);
				b *= C[i];
			}
			if(0.99 <= (double)a/b && (double)a/b <= 1.01) ans++;
		}
		bw.write(ans + "\n");
		
	}
	
}