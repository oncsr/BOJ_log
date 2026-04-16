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
		int N = nextInt(), S = nextInt();
		
		boolean[][][] d = new boolean[N+1][N][S+1];
		if(N < 3) {
			bw.write("0");
			bw.close();
			return;
		}
		d[3][1][1] = true;
		d[3][2][1] = true;
		boolean ans = N==3&&S==1 ? true : false;
		for(int n=3;n<N;n++) for(int k=1;k<n;k++) for(int s=1;s<=S;s++) if(d[n][k][s] && s+k<=S) {
			d[n+1][k+1][s+k] = true;
			d[n+1][1][s+k] = true;
			if(n+1==N && s+k==S) ans = true;
		}
		bw.write((ans ? "1" : "0"));
		
		bw.close();
	}

}