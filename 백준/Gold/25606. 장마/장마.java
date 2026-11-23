import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		// Code

		st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int Q = Integer.parseInt(st.nextToken());

		int[] arr = new int[N+2];
		st = new StringTokenizer(br.readLine());
		for(int i=1;i<=N;i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		int[][] queries = new int[Q][];
		for(int i=0;i<Q;i++) {
			st = new StringTokenizer(br.readLine());
			int op = Integer.parseInt(st.nextToken());
			int t = Integer.parseInt(st.nextToken());
			queries[i] = new int[]{op, t, i};
		}

		Arrays.sort(queries, (a,b) -> a[1]-b[1]);

		int day = 0, waters = 0, dries = 0;
		int[] dryCount = new int[N+2];
		int[] answer = new int[Q];
		for(int[] query : queries) {
			int op = query[0];
			int t = query[1];
			int idx = query[2];

			while(day < t) {
				day++;
				// arr[day] 처리
				dries += dryCount[day];
				waters += arr[day] - dries;
				dryCount[day+1] += M;
				int endDay = day + 1 + arr[day]/M;
				if(endDay <= N) {
					dryCount[endDay] -= M - (arr[day]%M);
					dryCount[endDay+1] -= arr[day]%M;
				}
			}

			if(op == 1) {
				answer[idx] = waters;
			}
			else {
				answer[idx] = dries;
			}
		}

		for(int i=0;i<Q;i++) {
			bw.write(answer[i] + "\n");
		}

		//

		bw.close();
		br.close();
	}
}
