import java.util.*;
import java.io.*;

class Main
{	
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		char[][] arr = new char[N][M];
		for(int i=0;i<N;i++) {
			String s = br.readLine();
			for(int j=0;j<M;j++) arr[i][j] = s.charAt(j);
		}
		
		int[][][][] G = new int[N][M][N][M];
		for(int n=0;n<N;n++) for(int m=0;m<M;m++) {
			for(int n1=0;n1+n<N;n1++) for(int m1=0;m1+m<M;m1++) {
				if(n == 0 && m == 0) {
					if(arr[n1][m1] == '.') G[n1][m1][n1][m1] = 1;
					else G[n1][m1][n1][m1] = 0;
					continue;
				}
				
				TreeSet<Integer> T = new TreeSet<>();
				
				for(int x=n1;x<=n1+n;x++) for(int y=m1;y<=m1+m;y++) {
					if(arr[x][y] == 'X') continue;
					int g = 0;
					if(n1 <= x-1 && m1 <= y-1) g ^= G[n1][m1][x-1][y-1];
					if(n1 <= x-1 && y+1 <= m1+m) g ^= G[n1][y+1][x-1][m1+m];
					if(x+1 <= n1+n && m1 <= y-1) g ^= G[x+1][m1][n1+n][y-1];
					if(x+1 <= n1+n && y+1 <= m1+m) g ^= G[x+1][y+1][n1+n][m1+m];
					T.add(g);
				}
				
				int mex = 0;
				for(int t:T) {
					if(t != mex) break;
					mex++;
				}
				G[n1][m1][n1+n][m1+m] = mex;
//				
//				// Debug
//				bw.write("("+n1+","+m1+") ~ ("+(n1+n)+","+(m1+m)+") = "+G[n1][m1][n1+n][m1+m]+"\n");
//				
			}
		}
		if(G[0][0][N-1][M-1] == 0) bw.write("Second");
		else bw.write("First");
		
		bw.flush();
		bw.close();
	}
}