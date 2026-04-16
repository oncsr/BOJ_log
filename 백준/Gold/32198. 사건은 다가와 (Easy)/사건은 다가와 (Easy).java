import java.util.*;
import java.io.*;

class Node{
	int x;
	int y;
	Node(int x, int y){
		this.x = x;
		this.y = y;
	}
}

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int N = Integer.parseInt(br.readLine());
		int[] dp = new int[2005];
		for(int i=0;i<2005;i++) dp[i] = -1;
		dp[1001] = 0;
		int maxtime = 0;
		
		boolean[][] bang = new boolean[2005][1002];
		for(int i=0;i<N;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int t = Integer.parseInt(st.nextToken());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			a += 1001;
			b += 1001;
			maxtime = Math.max(maxtime, t);
			for(int j=a+1;j<b;j++) bang[j][t] = true;
		}
		
		for(int y=1;y<=maxtime;y++) {
			int[] ndp = new int[2005];
			for(int i=0;i<2005;i++) ndp[i] = -1;
			for(int x=0;x<2005;x++) {
				if(bang[x][y]) continue;
				if(x>0 && dp[x-1] != -1) {
					if(ndp[x] == -1) ndp[x] = dp[x-1]+1;
					else ndp[x] = Math.min(ndp[x], dp[x-1]+1);
				}
				if(dp[x] != -1) {
					if(ndp[x] == -1) ndp[x] = dp[x];
					else ndp[x] = Math.min(ndp[x], dp[x]);
				}
				if(x<2004 && dp[x+1] != -1) {
					if(ndp[x] == -1) ndp[x] = dp[x+1]+1;
					else ndp[x] = Math.min(ndp[x], dp[x+1]+1);
				}
			}
			dp = ndp;
		}
		int ans = 1234567890;
		for(int i=0;i<2005;i++) {
			if(dp[i] == -1) continue;
			ans = Math.min(ans,dp[i]);
		}
		if(ans == 1234567890) bw.write("-1");
		else bw.write(ans+"\n");
		
		bw.close();
	}

}