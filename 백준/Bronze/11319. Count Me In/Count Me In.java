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
	
	static final char[] L = {'A','E','I','O','U','a','e','i','o','u'}; 
	static char[] line;
	
	public static void main(String[] args) throws Exception {
		
		for(int T=nextInt();T-->0;solve()) ready();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		line = br.readLine().toCharArray();
		
	}
	
	static void solve() throws Exception {
		
		int c = 0, v = 0;
		for(char i : line) if(i != ' ') {
			boolean ex = false;
			for(char j:L) ex |= j == i;
			if(ex) v++;
			else c++;
		}
		bw.write(c + " " + v + "\n");
		
	}
	
}