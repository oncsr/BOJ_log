import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		// Code

		final int INF = (int)1e9 + 7;

		st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int T = Integer.parseInt(st.nextToken()) - Integer.parseInt(st.nextToken());

		int[][] arr = new int[N][];
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			int s = Integer.parseInt(st.nextToken());
			int e = Integer.parseInt(st.nextToken());
			arr[i] = new int[]{s,e};
		}

		Arrays.sort(arr, (a,b) -> a[1]-b[1]);
		int[] prev = new int[N];
		prev[0] = -1;
		for(int i=1;i<N;i++) {
			int s = -1, e = i-1, m = (s+e+1) >> 1;
			int v = arr[i][0];
			while(s < e) {
				if(arr[m][1] <= v) {
					s = m;
				}
				else {
					e = m-1;
				}
				m = (s+e+1) >> 1;
			}
			prev[i] = m;
		}

		int answer = 0;
		int[][] dp = new int[N][N+1];
		for(int i=0;i<N;i++) for(int j=2;j<=N;j++) {
			dp[i][j] = INF;
		}

		for(int i=0;i<N;i++) {
			dp[i][1] = arr[i][1] - arr[i][0];
			if(i > 0) dp[i][1] = Math.min(dp[i-1][1], dp[i][1]);
			if(dp[i][1] <= T) answer = 1;
		}
		for(int i=1;i<N;i++) for(int j=2;j<=i+1;j++) {
			dp[i][j] = Math.min(dp[i][j], dp[i-1][j]);
			if(prev[i] != -1) dp[i][j] = Math.min(dp[i][j], dp[prev[i]][j-1] + arr[i][1] - arr[i][0]);
			if(dp[i][j] <= T) {
				answer = Math.max(answer, j);
			}
		}

		bw.write(answer + "\n");

		//

		bw.close();
		br.close();
	}
}
