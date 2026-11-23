import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		// Code

		long N = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		long A = Integer.parseInt(st.nextToken());
		long B = Integer.parseInt(st.nextToken());
		long C = Integer.parseInt(st.nextToken());

		long answer = 0;
		for(long y=1;y<=N;y++) {
			long xCount = Math.min(N, Math.max(0L, N - B*y/A));
			long zCount = Math.min(N, Math.max(0L, (B*y)%C == 0 ? B*y/C - 1 : B*y/C));
			answer += xCount * zCount;
		}

		bw.write(answer + "\n");

		//

		bw.close();
		br.close();
	}
}
