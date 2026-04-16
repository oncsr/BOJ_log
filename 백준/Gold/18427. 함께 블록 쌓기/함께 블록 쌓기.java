import java.util.*;
import java.io.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int h = Integer.parseInt(st.nextToken());
		
		int[] dp = new int[1001];
		dp[0] = 1;
		int mod = 10007;
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			int[] ndp = new int[1001];
			for(int j=0;j<=h;j++) ndp[j] = dp[j];
			while(st.hasMoreTokens()) {
				int a = Integer.parseInt(st.nextToken());
				for(int j=a;j<=h;j++) ndp[j] = (ndp[j] + dp[j-a]) % mod;
			}
			for(int j=0;j<=h;j++) dp[j] = ndp[j];
		}
		bw.write(dp[h] + "\n");
		
		bw.flush();
		bw.close();
	}
}