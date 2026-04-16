import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		/*
		 * 초기에 폭탄이 존재하는 자리를 A라 하고,
		 * A와 인접한 자리를 B, 
		 * A,B가 아닌 자리를 C,
		 * C와 인접하지 않은 자리를 D라고 하면,
		 * 
		 * 1. N >= 7인 경우
		 *   1-1. N%4 == 3인 경우
		 * 		C에만 폭탄이 존재합니다.
		 *   1-2. N%4 == 1인 경우
		 *      D에만 폭탄이 존재합니다.
		 *   1-3. 둘 다 아닌 경우
		 *      모든 칸에 폭탄이 존재합니다.
		 * 2. N < 7인 경우
		 *   직접 시뮬레이션하여 A, B, C, D를 구한 뒤 출력합니다.
		 */
		
		int[] dx = {1,0,-1,0,0};
		int[] dy = {0,1,0,-1,0};
		
		st = new StringTokenizer(br.readLine());
		
		int R = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());
		
		int[][][] A = new int[R][C][7];
		
		for(int i=0;i<R;i++) {
			char[] temp = br.readLine().toCharArray();
			for(int j=0;j<C;j++) {
				if(temp[j] == 'O') {
					A[i][j][0] = 3;
					A[i][j][1] = 2;
					A[i][j][2] = 1;
				}
				else A[i][j][2] = 3;
			}
		}
		
		int turn = 1;
		for(int t=3;t<7;t++) {
			if(turn == 1) {
				for(int i=0;i<R;i++) for(int j=0;j<C;j++) A[i][j][t] = A[i][j][t-1];
				for(int i=0;i<R;i++) for(int j=0;j<C;j++) if(A[i][j][t-1] == 1) {
					for(int k=0;k<4;k++) {
						int x = i+dx[k], y = j+dy[k];
						if(x<0 || x>=R || y<0 || y>=C) continue;
						A[x][y][t] = 0;
					}
				}
				for(int i=0;i<R;i++) for(int j=0;j<C;j++) {
					if(A[i][j][t] != 0) A[i][j][t] = A[i][j][t-1] - 1;
				}
			}
			else {
				for(int i=0;i<R;i++) for(int j=0;j<C;j++) A[i][j][t] = A[i][j][t-1] == 0 ? 3 : A[i][j][t-1] - 1;
			}
			turn ^= 1;
		}
		
		int idx = -1;
		if(N <= 6) idx = N;
		else idx = N%4 == 3 ? 3 : N%4 + 4;
		for(int i=0;i<R;i++) {
			for(int j=0;j<C;j++) {
				bw.write(A[i][j][idx] == 0 ? "." : "O");
			}
			bw.write("\n");
		}
		
		bw.flush();
		bw.close();
		
	}

}
