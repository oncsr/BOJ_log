import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		//--------------솔루션 코드를 작성하세요.--------------------------------
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		// 카드 정렬 후 두 개의 카드는 고정시켜두고 나머지 하나를 이분 탐색으로 찾기
		// O(N^2 * logN)
		
		st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		int[] A = new int[N];
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<N;i++) A[i] = Integer.parseInt(st.nextToken());
		
		Arrays.sort(A);
		
		int ans = 0;
		for(int i=0;i<N;i++) for(int j=i+1;j<N-1;j++) {
			int s = j+1, e = N-1, m = (s+e+1)>>1;
			while(s<e) {
				if(A[i] + A[j] + A[m] > M) e = m-1;
				else s = m;
				m = (s+e+1)>>1;
			}
			if(A[i] + A[j] + A[m] <= M) ans = Math.max(ans, A[i] + A[j] + A[m]);
		}
		bw.write(ans + "\n");
		
		bw.flush();
		bw.close();
	}

}
