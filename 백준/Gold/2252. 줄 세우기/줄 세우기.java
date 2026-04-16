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

	static int N, M;
	static List<Integer>[] V;
	static int[] D;
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		nextLine();
		N = nextInt();
		M = nextInt();
		V = new List[N+1];
		D = new int[N+1];
		for(int i=1;i<=N;i++) V[i] = new ArrayList<>();
		
		while(M-- > 0) {
			nextLine();
			int a = nextInt(), b = nextInt();
			D[b]++;
			V[a].add(b);
		}
		
	}
	
	static void solve() throws Exception{
		
		tpst();
		
	}
	
	static void tpst() throws Exception {
		
		Queue<Integer> Q = new LinkedList<>();
		for(int i=1;i<=N;i++) if(D[i] == 0) Q.add(i);
		
		while(!Q.isEmpty()) {
			int n = Q.poll();
			bw.write(n + " ");
			for(int i:V[n]) if(--D[i] == 0) Q.add(i);
		}
		
	}
	
}