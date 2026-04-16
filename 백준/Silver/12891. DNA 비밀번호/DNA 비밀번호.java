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
	
	static int S, P, A, C, G, T;
	static char[] X;
	
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{

		nextLine();
		S = nextInt();
		P = nextInt();
		
		X = br.readLine().toCharArray();
		
		nextLine();
		A = nextInt();
		C = nextInt();
		G = nextInt();
		T = nextInt();
		
	}
	
	static void solve() throws Exception{

		int a = 0, c = 0, g = 0, t = 0, ans = 0;
		for(int i=0;i<P;i++) {
			if(X[i] == 'A') a++;
			if(X[i] == 'C') c++;
			if(X[i] == 'G') g++;
			if(X[i] == 'T') t++;
			
		}
		if(a>=A && c>=C && g>=G && t>=T) ans++;
		for(int i=P;i<S;i++) {
			if(X[i] == 'A') a++;
			if(X[i] == 'C') c++;
			if(X[i] == 'G') g++;
			if(X[i] == 'T') t++;
			
			if(X[i-P] == 'A') a--;
			if(X[i-P] == 'C') c--;
			if(X[i-P] == 'G') g--;
			if(X[i-P] == 'T') t--;
			
			if(a>=A && c>=C && g>=G && t>=T) ans++;
		}
		bw.write(ans + "\n");
		
	}
	
}