import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	static int[] r;
	
	public static void main(String[] args) throws Exception {
		//--------------솔루션 코드를 작성하세요.--------------------------------
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		// 각 칸의 안전 점수가 큰 순서대로 정렬 후,
		// 꽃가루 농도를 100에서부터 아래로 스위핑하며 분리 집합으로 영역 연결 및 개수 관리
		// => amortized O(N^2 log(N^2))
		//
		// 분리 집합은 1차원으로 관리 (x,y) => x*N + y
		
		int[] dx = {1,0,-1,0};
		int[] dy = {0,1,0,-1};
		
		int N = Integer.parseInt(br.readLine());
		int[][] A = new int[N][N];
		int[][] info = new int[N*N][2];
		boolean[] vis = new boolean[N*N];
		
		r = new int[N*N];
		for(int i=0;i<N*N;i++) r[i] = i;
		
		int id = 0;
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<N;j++) {
				A[i][j] = Integer.parseInt(st.nextToken());
				info[id++] = new int[] {A[i][j], i*N + j};
			}
		}
		
		Arrays.sort(info, (a,b) -> a[0]-b[0]);
		
		int ans = 0, cnt = 0;
		id--;
		while(id >= 0) {
			int val = info[id][0];
			while(id >= 0 && info[id][0] == val) {
				int base = info[id][1];
				vis[base] = true;
				cnt++;
				int x = base / N, y = base % N;
				for(int k=0;k<4;k++) {
					int xx = x+dx[k], yy = y+dy[k], side = xx*N + yy;
					if(xx<0 || xx>=N || yy<0 || yy>=N || !vis[side]) continue;
					
					int p = f(base), q = f(side);
					if(p != q) {
						cnt--;
						r[p] = q;
					}
					
				}
				id--;
			}
			ans = Math.max(ans, cnt);
		}
		
		bw.write(ans + "\n");
		
		bw.flush();
		bw.close();
	}
	
	public static int f(int x) {return x==r[x] ? x : (r[x]=f(r[x]));}

}
