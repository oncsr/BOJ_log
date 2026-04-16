import java.util.*;
import java.io.*;

class Node{
	int x;
	int y;
	int t;
	Node(int x, int y, int t){
		this.x = x;
		this.y = y;
		this.t = t;
	}
}

public class Main {
	static StringTokenizer st;
	static int nextInt() { return Integer.parseInt(st.nextToken()); }

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		st = new StringTokenizer(br.readLine());
		int N = nextInt(), M = nextInt();
		int[][] arr = new int[3300][3300];
		boolean[][] vis = new boolean[3300][3300];
		Queue<Node> Q = new LinkedList<>();
		for(int i=0;i<N;i++) {
			String s = br.readLine();
			for(int j=0;j<M;j++) {
				arr[i+1600][j+1600] = s.charAt(j)=='.' ? 0 : 1;
			}
		}
		int K = Integer.parseInt(br.readLine());
		
		for(int i=0;i<N;i++) for(int j=0;j<M;j++) {
			if(arr[i+1600][j+1600] == 1) {
				Q.offer(new Node(i+1600, j+1600, K));
				vis[i+1600][j+1600] = true;
			}
		}
		
		int[] dx = {1,0,-1,0};
		int[] dy = {0,1,0,-1};
		int ans = 0;
		while(!Q.isEmpty()) {
			Node now = Q.poll();
			ans++;
			if(now.t == 0) continue;
			for(int i=0;i<4;i++) {
				int x = now.x+dx[i], y = now.y+dy[i], t = now.t-1;
				if(vis[x][y]) continue;
				Q.offer(new Node(x,y,t));
				vis[x][y] = true;
			}
		}
		
		bw.write(ans+"\n");
		
		bw.close();
	}

}