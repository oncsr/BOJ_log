import java.util.*;
import java.io.*;

public class Main {
	static StringTokenizer st;
	static int nextInt() { return Integer.parseInt(st.nextToken()); }
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int N = Integer.parseInt(br.readLine());
		int[] A = new int[N];
		int[] E = new int[1000001];
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<N;i++) {
			A[i] = nextInt();
			E[A[i]]++;
		}
		for(int i=0;i<N;i++) {
			int score = A[i] == 1 ? 0 : -E[1];
			for(int j=A[i]*2;j<=1000000;j+=A[i]) score += E[j];
			for(int j=2;j*j<=A[i];j++) {
				if(A[i] % j != 0) continue;
				score -= E[j];
				if(j != A[i]/j) score -= E[A[i]/j];
			}
			bw.write(score+" ");
		}
		
		bw.close();
	}

}