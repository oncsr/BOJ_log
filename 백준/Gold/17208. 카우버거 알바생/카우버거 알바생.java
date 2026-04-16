import java.util.*;
import java.io.*;

public class Main {
	static StringTokenizer st;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static int nextInt() { return Integer.parseInt(st.nextToken()); }
	static void newLine() throws Exception { st = new StringTokenizer(br.readLine()); }
	
	public static void main(String[] args) throws Exception {
		
		newLine();
		int N = nextInt(), M = nextInt(), K = nextInt();
		int[][] D = new int[M+1][K+1];
		int ans = 0;
		for(int i=0;i<N;i++) {
			newLine();
			int x = nextInt(), y = nextInt();
			for(int m=M;m>=0;m--) for(int k=K;k>=0;k--) {
				if(m >= x && k >= y) D[m][k] = Math.max(D[m][k], D[m-x][k-y]+1);
				ans = Math.max(ans, D[m][k]);
			}
		}
		bw.write(ans+"\n");
		bw.close();
	}

}