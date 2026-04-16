import java.util.*;
import java.io.*;

class Main {
	
	// IO field
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st = new StringTokenizer("");

	static void nextLine() throws Exception {st = new StringTokenizer(br.readLine());}
	static String nextToken() throws Exception {
		while(!st.hasMoreTokens()) nextLine();
		return st.nextToken();
	}
	static int nextInt() throws Exception { return Integer.parseInt(nextToken()); }
	static long nextLong() throws Exception { return Long.parseLong(nextToken()); }
	static double nextDouble() throws Exception { return Double.parseDouble(nextToken()); }
	static void bwEnd() throws Exception {bw.flush();bw.close();}
	
	// Additional field
	
	static int N, M;
	static TreeSet<String> T;
	static int[] idx, arr;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = nextInt();
		T = new TreeSet<>();
		idx = new int[M];
		arr = new int[M];
		for(int i=0;i<M;i++) idx[i] = nextInt();
		char[] temp = br.readLine().toCharArray();
		for(int i=0;i<M;i++) arr[i] = temp[i] == '+' ? 1 : -1;
		
	}
	
	static void solve() throws Exception{
		
		String pos = "";
		TreeSet<Integer> used = new TreeSet<>();
		int R = 0;
		for(int i=0;i<M;i++) if(!used.contains(idx[i])){
			R++;
			used.add(idx[i]);
			pos += idx[i] + ":0 ";
		}
		
		T.add(pos);
		for(int i=0;i<M;i++) {
			String[] temp = pos.split(" ");
			String next = "";
			for(int j=0;j<temp.length;j++) {
				String[] tmp = temp[j].split(":");
				if(Integer.parseInt(tmp[0]) != idx[i]) next += temp[j] + " ";
				else {
					next += idx[i] + ":" + (Integer.parseInt(tmp[1]) + arr[i]) + " ";
				}
				
			}
			pos = next;
			if(T.contains(pos)) {
				bw.write("0");
				return;
			}
			T.add(pos);
		}
		bw.write("1");
		
	}
	
}