import java.util.*;
import java.io.*;

class Main
{	
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int N = Integer.parseInt(br.readLine());
		char[][] arr = new char[N][N];
		for(int i=0;i<N;i++) {
			String s = br.readLine();
			for(int j=0;j<s.length();j++) arr[i][j] = s.charAt(j);
		}
		int[][] del = new int[N][N];
		
		int[] dx = {-1,-1,-1,0,0,1,1,1};
		int[] dy = {-1,0,1,-1,1,-1,0,1};
		
		int M = Integer.parseInt(br.readLine());
		while(M-->0) {
			String s = br.readLine();
			if(s.length() > N) continue;
			for(int i=0;i<N;i++) {
				for(int j=0;j<N;j++) {
					for(int k=0;k<8;k++) {
						String temp = "" + arr[i][j];
						int x = i+dx[k], y = j+dy[k];
						if(temp.equals(s)) {
							int xx = i, yy = j;
							while(xx!=x || yy!=y) {
								del[xx][yy] = 1;
								xx += dx[k];
								yy += dy[k];
							}
							break;
						}
						while(0<=x && x<N && 0<=y && y<N) {
							temp += arr[x][y];
							x += dx[k];
							y += dy[k];
							if(temp.equals(s)) {
								int xx = i, yy = j;
								while(xx!=x || yy!=y) {
									del[xx][yy] = 1;
									xx += dx[k];
									yy += dy[k];
								}
								break;
							}
						}
					}
				}
			}
		}
		for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(del[i][j] == 0) bw.write(arr[i][j]);
		
		bw.flush();
		bw.close();
	}
}