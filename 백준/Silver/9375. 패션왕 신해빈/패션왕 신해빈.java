import java.util.*;
import java.io.*;

public class Main {
	
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
	
	static int N;
	static Map<String, Set<String>> M;
	
	public static void main(String[] args) throws Exception {
		
		for(int T=nextInt();T-->0;solve()) ready();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		M = new TreeMap<>();
		for(int i=0;i<N;i++) {
			String name = nextToken(), type = nextToken();
			if(!M.containsKey(type)) M.put(type, new TreeSet<>());
			M.get(type).add(name);
		}
		
	}
	
	static void solve() throws Exception {
		
		long ans = 1;
		for(String key : M.keySet()) ans *= (M.get(key).size() + 1);
		bw.write((ans-1) + "\n");
		
	}
	
}