import java.util.*;
import java.io.*;

public class Main {
	static StringTokenizer st;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static int nextInt() { return Integer.parseInt(st.nextToken()); }
	static void newLine() throws Exception { st = new StringTokenizer(br.readLine()); }
	
	static int[] len;
	static char sol(int n, int k) {
		if(n == 0) {
			if(k == 1) return 'm';
			return 'o';
		}
		if(k <= len[n-1]) return sol(n-1,k);
		if(k > len[n-1] + n+3) return sol(n-1, k - (len[n-1] + n+3));
		if(k == len[n-1] + 1) return 'm';
		return 'o';
	}
	
	public static void main(String[] args) throws Exception {

		int N = Integer.parseInt(br.readLine());
		len = new int[100];
		len[0] = 3;
		int d = 4, i=1;
		for(;len[i-1] <= (int)1e9;i++) len[i] = len[i-1]*2 + (d++);
		bw.write(sol(27,N));

		bw.close();
	}

}