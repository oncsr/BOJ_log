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

		int N = Integer.parseInt(br.readLine());
		for(int i=0;i<2*N;i++) {
			for(int j=0;j<N;j++) bw.write((i+j)%2 == 0 ? '*' : ' ');
			bw.write("\n");
		}
		
		
		bwEnd();
	}

}