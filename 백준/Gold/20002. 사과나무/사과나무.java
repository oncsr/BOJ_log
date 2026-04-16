import java.util.*;
import java.io.*;

public class Main {
	static StringTokenizer st;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static int nextInt() { return Integer.parseInt(st.nextToken()); }
	static void newLine() throws Exception { st = new StringTokenizer(br.readLine()); }
	
	public static void main(String[] args) throws Exception {

		int N = Integer.parseInt(br.readLine());
		
		int[][] arr = new int[N+1][N+1];
		int[][] sum = new int[N+1][N+1];
		for(int i=1;i<=N;i++) {
			newLine();
			for(int j=1;j<=N;j++) {
				arr[i][j] = nextInt();
				sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
			}
		}
		
		int ans = -1234567890;
		for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) for(int k=0;i+k<=N&&j+k<=N;k++) {
			ans = Math.max(ans, sum[i+k][j+k]-sum[i-1][j+k]-sum[i+k][j-1]+sum[i-1][j-1]);
		}
		bw.write(ans+"\n");
		
		bw.close();
	}

}