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
	static List<Integer> list;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		nextLine();
		N = nextInt();
		M = nextInt();
		list = new ArrayList<>();
		
	}
	
	static void solve() throws Exception{

		bck(0,0);
		
	}

	static void bck(int cnt, int last) throws Exception{
		if(cnt == M) {
			for(int i:list) bw.write(i + " ");
			bw.write("\n");
			return;
		}
		
		for(int i=last+1;i<=N;i++) {
			list.add(i);
			bck(cnt+1, i);
			list.remove(list.size()-1);
		}
	}
	
}