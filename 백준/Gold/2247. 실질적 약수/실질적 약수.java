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
	

	public static void main(String[] args) throws Exception {

		nextLine();
		long ans = 0, N = nextLong();
		for(long i=2;i<N;i++) ans += (N/i - 1) * i;
		bw.write((ans%1000000)+"\n");
		
		bwEnd();
	}

}