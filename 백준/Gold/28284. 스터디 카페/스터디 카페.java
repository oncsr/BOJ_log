import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		long[] S1 = new long[N];
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<N;i++) S1[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(S1);
		long[] S2 = new long[N];
		for(int i=0;i<N;i++) S2[i] = S1[N-i-1];
		for(int i=1;i<N;i++) {
			S1[i] += S1[i-1];
			S2[i] += S2[i-1];
		}
		
		int[] hi = new int[M];
		int[] bye = new int[M];
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			hi[i] = Integer.parseInt(st.nextToken());
			bye[i] = Integer.parseInt(st.nextToken()) + 1;
		}
		Arrays.sort(hi);
		Arrays.sort(bye);
		int i = 0, j = 0;
		
		long ans1 = 0, ans2 = 0, cur = 0, time = 0;
		while(j < M) {
			int t = bye[j];
			if(i < M) t = Math.min(t, hi[i]);
			if(cur > 0) {
				ans1 += ((long)t - time) * S1[(int)cur-1];
				ans2 += ((long)t - time) * S2[(int)cur-1];
			}
			while(i<M && t == hi[i]) {
				cur++;
				i++;
			}
			while(j<M && t == bye[j]) {
				cur--;
				j++;
			}
			time = t;
		}
		bw.write(ans1+" "+ans2);
		
		bw.flush();
		bw.close();
	}

}
