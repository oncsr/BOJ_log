import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		// Code

		int N = Integer.parseInt(br.readLine()) / 2;
		int[][] arr = new int[N*2][];
		for(int i=0;i<N*2;i++) {
			st = new StringTokenizer(br.readLine());
			int h = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			arr[i] = new int[]{h,w};
		}
		Arrays.sort(arr, (a,b) -> a[0]-b[0]);

		int deleted = -1;
		int answer = 0;
		int lastPeek = -1;
		PriorityQueue<Integer> pq = new PriorityQueue<>((a,b) -> b-a);
		for(int i=0;i<N*2;) {
			int curH = arr[i][0];
			while(i < N*2 && arr[i][0] == curH) {
				pq.offer(arr[i][1]);
				i++;
			}

			while(pq.size() > N) {
				deleted = pq.poll();
			}

			if(pq.size() == N && pq.peek() != deleted && pq.peek() != lastPeek) {
				answer++;
			}
			if(pq.size() == N) lastPeek = pq.peek();
		}
		bw.write(answer + "\n");

		//

		bw.close();
		br.close();
	}
}
