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
	static long nextLong() throws Exception {
		if(!st.hasMoreTokens()) nextLine();
		return Long.parseLong(st.nextToken());
	}
	static void bwEnd() throws Exception {bw.flush();bw.close();}
	
	// Additional field
	
	static int N, R, C;
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		R = nextInt();
		C = nextInt();
		
	}
	
	static void solve() throws Exception{
		
		if(N == 3) {
			if(R==2 && C==2) bw.write("1");
			else bw.write("4");
		}
		else {
			long white = (long)N*N/2;
			if(N%2 == 1) white++;
			bw.write(((R+C)%2 == 0 ? white : ((long)N*N-white)) + "\n");			
		}
		
	}
	
}