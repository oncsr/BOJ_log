import java.util.*;
import java.io.*;

public class Main {
	static StringTokenizer st;
	static int nextInt() { return Integer.parseInt(st.nextToken()); }

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		st = new StringTokenizer(br.readLine());
		int N = nextInt(), W = nextInt();
		
		int[][] info = new int[N][2];
		int la = 0, lb = 0;
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			info[i][0] = nextInt();
			info[i][1] = nextInt();
			if(info[i][0] == 5) la++;
			else lb++;
		}
		Long[] A = new Long[la];
		Long[] B = new Long[lb];
		int pa = 0, pb = 0;
		for(int i=0;i<N;i++) {
			if(info[i][0] == 5) A[pa++] = (long)info[i][1];
			else B[pb++] = (long)info[i][1];
		}
		Arrays.sort(A, Collections.reverseOrder());
		Arrays.sort(B, Collections.reverseOrder());
		for(int i=1;i<pa;i++) A[i] += A[i-1];
		for(int i=1;i<pb;i++) B[i] += B[i-1];
		
		long ans = 0;
		for(int i=0;i<=pa && i*5 <= W;i++) {
			long v = i==0 ? 0 : A[i-1];
			int p = (W-5*i)/3;
			if(p>0 && pb>0) v += B[Math.min(pb-1, p-1)];
			ans = Math.max(ans, v);
		}
		bw.write(ans+"\n");
		
		bw.close();
	}

}