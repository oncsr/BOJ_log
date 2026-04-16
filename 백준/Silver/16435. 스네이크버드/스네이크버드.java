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

	static int N, L;
	static int[] C;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{

		nextLine();
		N = nextInt();
		L = nextInt();
		C = new int[10001];
		
		nextLine();
		for(int i=0;i<N;i++) C[nextInt()]++;
		
	}
	
	static void solve() throws Exception{

		for(int i=1;i<=10000;i++) while(L >= i && C[i] > 0) {
			L++;
			C[i]--;
		}
		bw.write(L + "\n");
		
	}
	
}