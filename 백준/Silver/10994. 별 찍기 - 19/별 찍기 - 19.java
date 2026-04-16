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
		int N = nextInt();
		for(int i=0;i<4*N-3;i++) {
			for(int j=0;j<4*N-3;j++) {
				if(Math.max(Math.abs(2*N-2 - i), Math.abs(2*N-2 - j)) % 2 == 0) bw.write("*");
				else bw.write(" ");
			}
			bw.write("\n");
		}
		
		bwEnd();
	}

}