import java.util.*;
import java.io.*;

public class Main {
	static StringTokenizer st;
	static int nextInt() { return Integer.parseInt(st.nextToken()); }
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		st = new StringTokenizer(br.readLine());
		int N = nextInt(), M = nextInt(), S = nextInt(), T = nextInt();
		int INF = (int)1e9;
		int[][] C = new int[301][301];
		for(int i=0;i<301;i++) {
			Arrays.fill(C[i], INF);
			C[i][i] = 0;
		}
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			int a = nextInt(), b = nextInt(), c = nextInt();
			C[a][b] = Math.min(C[a][b], c);
		}
		for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) for(int k=1;k<=N;k++) {
			C[j][k] = Math.min(C[j][k], C[j][i]+C[i][k]);
		}

		int Q = Integer.parseInt(br.readLine()); 
		while(Q-->0){
			st = new StringTokenizer(br.readLine());
			int a = nextInt(), b = nextInt(), c = nextInt(), d = nextInt(), e = nextInt(), f = nextInt();
			int ans = C[S][T];
			ans = Math.min(ans, C[S][a] + c + C[b][T]);
			ans = Math.min(ans, C[S][d] + f + C[e][T]);
			if(C[S][a]!=INF && C[b][d]!=INF && C[e][T]!=INF) ans = Math.min(ans, C[S][a] + c + C[b][d] + f + C[e][T]);
			if(C[S][d]!=INF && C[e][a]!=INF && C[b][T]!=INF) ans = Math.min(ans, C[S][d] + f + C[e][a] + c + C[b][T]);
			bw.write((ans==INF ? -1 : ans)+"\n");
		}
		
		bw.close();
	}

}