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
		
		int T = Integer.parseInt(br.readLine());
		while(T-- > 0){
    		ready();
    		solve();
		}
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{

        nextLine();
        A = st.nextToken();
        B = st.nextToken();
		
	}
	
	static void solve() throws Exception{

        long res1 = Long.parseLong(A) * Long.parseLong(B);
        
        String res2 = "";
        int idx1 = 0, idx2 = 0;
        while(A.length() - idx1 != B.length() - idx2){
            if(A.length()-idx1 > B.length()-idx2) res2 += A.charAt(idx1++);
            else res2 += B.charAt(idx2++);
        }
        
        while(idx1 < A.length()) {
            int a = A.charAt(idx1++) - '0';
            int b = B.charAt(idx2++) - '0';
            res2 += a*b;
        }
        
        bw.write(Long.parseLong(res2) == res1 ? "1\n" : "0\n");
		
	}
	
	
}