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
	static int ans = 0;
	static int[] S;
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = Integer.parseInt(br.readLine());
		S = new int[N];
		nextLine();
		for(int i=0;i<N;i++) S[i] = nextInt();
		
	}
	
	static void solve() throws Exception{
		
		Arrays.sort(S);
		int p = 0;
		for(int i=0;i<N;i++) if(S[i] >= 2*p) {
			p = S[i];
			ans++;
		}
		bw.write(ans + "\n");
		
	}
	
}