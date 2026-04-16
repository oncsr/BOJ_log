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
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
	}
	
	static void solve() throws Exception{
		
		int lineNum = 0;
		int[] idx = new int[127];
		boolean[] used = new boolean[127];
		String line;
		while(true){
		    lineNum++;
		    line = br.readLine().stripLeading();
		    if(line.length() > 20){
		        idx[line.charAt(9)] = lineNum;
		        continue;
		    }
		    for(char i:line.toCharArray()) used[i] = true;
		    break;
		}
		
		int cnt = 0;
		for(int i=1;i<=lineNum;i++){
		    for(char j='a';j<='z';j++) if(used[j] && idx[j] == i){
		        for(int k=0;k<cnt;k++) bw.write(" ");
		        cnt++;
		        bw.write("for (int " + j + " = 1; " + j + " < 9; " + j + "++)\n");
		    }
		    for(char j='A';j<='Z';j++) if(used[j] && idx[j] == i){
		        for(int k=0;k<cnt;k++) bw.write(" ");
		        cnt++;
		        bw.write("for (int " + j + " = 1; " + j + " < 9; " + j + "++)\n");
		    }
		}
		for(int k=0;k<cnt;k++) bw.write(" ");
		bw.write(line);
		
	}
	
}
