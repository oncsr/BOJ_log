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
	static int[] C;
	static int N;
	static List<Integer>[] V;
	static TreeSet<Integer>[] D;
	static int[] X;
	static boolean[] canWin;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
	}
	
	static void ready() throws Exception{
		
		N = Integer.parseInt(br.readLine());
		C = new int[N+1];
		D = new TreeSet[N+1];
		V = new List[N+1];
		X = new int[N+1];
		canWin = new boolean[N+1];
		
		nextLine();
		for(int i=1;i<=N;i++) {
			C[i] = nextInt();
			D[i] = new TreeSet<>();
			V[i] = new ArrayList<>();
			D[i].add(C[i]);
		}
		
		for(int i=1;i<N;i++) {
			nextLine();
			int a = nextInt(), b = nextInt();
			V[a].add(b);
			V[b].add(a);
		}
		
	}
	
	static void solve() throws Exception{

		dfs(1, 0);
		
		bw.write(canWin[1] ? "kidw0124" : "eoaud0108");
		
	}
	
	static void dfs(int n, int p) throws Exception {
		
		int S = 0;
		boolean f = false;
		for(int i:V[n]) {
			if(i == p) continue;
			dfs(i,n);
			
			// 님 게임을 이길 수 있는 경로가 있다면
			if(canWin[i]) {
				S++;
				f = D[i].contains(X[i]^C[n]);
			}
			
			
			X[i] ^= C[n];
			
			if(D[n].size() < D[i].size()) {
				TreeSet<Integer> temp = D[n];
				D[n] = D[i];
				D[i] = temp;
				int x = X[n];
				X[n] = X[i];
				X[i] = x;
			}
			
			for(int k:D[i]) D[n].add(k^X[i]^X[n]);
			
			D[i] = new TreeSet<>();
			
			
		}
		
		if(S >= 2) canWin[n] = false;
		else if(S == 0) canWin[n] = D[n].contains(X[n]);
		else canWin[n] = f;
		
	}
	
	
}