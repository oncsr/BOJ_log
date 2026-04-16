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

  static String A, B;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{

  	A = br.readLine();
  	B = br.readLine();
		
	}
	
	static void solve() throws Exception{

    if(A.equals("null")){
      bw.write("NullPointerException\nNullPointerException");
      return;
    }
    
    if(B.equals("null")){
      bw.write("false\nfalse");
      return;
    }
    
    bw.write(A.equals(B) ? "true\n" : "false\n");
    bw.write(A.equalsIgnoreCase(B) ? "true" : "false");
		
	}
	
	
}