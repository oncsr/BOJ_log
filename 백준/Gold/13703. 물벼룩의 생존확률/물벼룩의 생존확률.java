import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int k = sc.nextInt(), n = sc.nextInt();
		long[][] dp = new long[64][128];
		dp[0][k] = 1;
		long ans = 0;
		for(int i=1;i<=n;i++) {
			for(int j=Math.max(1, k-i);j<=k+i;j++) {
				dp[i][j] += dp[i-1][j+1];
				if(j > 1) dp[i][j] += dp[i-1][j-1];
				if(i == n) ans += dp[i][j];
			}
		}
		System.out.print(ans);
		
	}
}
