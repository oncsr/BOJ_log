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
	static long K;
	static long[] X;
	
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{

		nextLine();
		N = nextInt();
		K = nextLong();
		X = new long[N];
		for(int i=0;i<N;i++) X[i] = Long.parseLong(br.readLine()); 
		
	}
	
	static void solve() throws Exception{
		
		long s = 0, e = (long)2e9 + 1, m = (s+e+1)>>1;
		while(s<e) {
			long need = 0;
			for(int i=0;i<N;i++) need += Math.max(m-X[i], 0L);
			if(need <= K) s = m;
			else e = m-1;
			m = (s+e+1)>>1;
		}
		bw.write(m + "\n");
		
	}
	
}