import java.util.*;
import java.io.*;

public class Main {
	static StringTokenizer st;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static int nextInt() { return Integer.parseInt(st.nextToken()); }
	static void newLine() throws Exception { st = new StringTokenizer(br.readLine()); }
	
	public static void main(String[] args) throws Exception {

		int[][] dp = new int[2001][2001];
		int[][] s = new int[2001][2001];
		int mod = 100999;
		
		for(int i=0;i<=2000;i++) s[0][i] = 1;
		for(int i=1;i<=2000;i++) s[1][i] = 1;
		dp[1][1] = 1;
		s[1][1] = 1;
		for(int i=2;i<=2000;i++) for(int j=1;j<=2000;j++) {
			if(j <= i) {
				dp[i][j] = s[i-j][j-1];
				s[i][j] = (dp[i][j] + s[i][j-1]) % mod;				
			}
			else s[i][j] = s[i][j-1];
		}
		int[] ans = new int[2001];
		for(int i=1;i<=2000;i++) for(int j=1;j<=i;j++) ans[i] = (ans[i] + dp[i][j]) % mod;
		
		for(int T=Integer.parseInt(br.readLine());T-->0;) bw.write(ans[Integer.parseInt(br.readLine())]+"\n");

		bw.close();
	}

}