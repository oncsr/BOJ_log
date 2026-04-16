import java.util.*;
import java.io.*;

class Ticket implements Comparable<Ticket>{
	long w, p;
	int id;
	public Ticket(int w, int p, int id) {
		this.w = w;
		this.p = p;
		this.id = id;
	}
	@Override
	public int compareTo(Ticket other) {
		long resThis = this.w * (10000 - this.p) + (this.w + other.w) * this.p; 
		long resOther = other.w * (10000 - other.p) + (this.w + other.w) * other.p;
		if(resThis > resOther) return -1;
		if(resThis < resOther) return 1;
		return this.id-other.id;
	}
}

class Main {
	
	// IO field
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st = new StringTokenizer("");

	static void nextLine() throws Exception {st = new StringTokenizer(br.readLine());}
	static String nextToken() throws Exception {
		if(!st.hasMoreTokens()) nextLine();
		return st.nextToken();
	}
	static int nextInt() throws Exception { return Integer.parseInt(nextToken()); }
	static long nextLong() throws Exception { return Long.parseLong(nextToken()); }
	static double nextDouble() throws Exception { return Double.parseDouble(nextToken()); }
	static void bwEnd() throws Exception {bw.flush();bw.close();}
	
	// Additional field
	
	static int N;
	static Ticket[] A;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		A = new Ticket[N];
		for(int i=0;i<N;i++) {
			int w = nextInt(), p = nextInt(), id = i+1;
			A[i] = new Ticket(w,p,id);
		}
		
	}
	
	static void solve() throws Exception{

		Arrays.sort(A);
		for(Ticket t:A) bw.write(t.id + " ");
		
	}
	
}