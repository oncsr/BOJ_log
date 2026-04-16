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
	static char[][] A, B;
	
	static int[] r;
	static int f(int x) { return x==r[x] ? x : (r[x]=f(r[x])); }
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = Integer.parseInt(br.readLine());
		A = new char[N][];
		B = new char[N][N];
		for(int i=0;i<N;i++) {
			A[i] = br.readLine().toCharArray();
			for(int j=0;j<N;j++) B[i][j] = A[i][j] == 'B' ? 'B' : 'R';
		}
		
	}
	
	static void solve() throws Exception{
		
		bw.write(ff(A) + " " + ff(B));
		
	}
	
	static int ff(char[][] T) {
		
		r = new int[N*N];
		for(int i=0;i<N*N;i++) r[i] = i;
		
		
		for(int i=0;i<N;i++) for(int j=0;j<N;j++) {
			if(i>0 && T[i][j] == T[i-1][j]) {
				int x = f(i*N+j), y = f((i-1)*N+j);
				if(x != y) r[x] = y;
			}
			if(j>0 && T[i][j] == T[i][j-1]) {
				int x = f(i*N+j), y = f(i*N+j-1);
				if(x != y) r[x] = y;
			}
		}
		boolean[] v = new boolean[N*N];
		int ans = 0;
		
		for(int i=0;i<N*N;i++) if(!v[f(i)]) {
			v[f(i)] = true;
			ans++;
		}
		return ans;
		
	}
	
}