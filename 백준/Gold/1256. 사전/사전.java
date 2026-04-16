import java.util.*;
import java.io.*;

public class Main {
	static StringTokenizer st;
	static int nextInt() { return Integer.parseInt(st.nextToken()); }
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		st = new StringTokenizer(br.readLine());

		long N = nextInt(), M = nextInt(), K = nextInt();
		
		long kk = M;
		String ans = "";
		while(K > 1) {
			long C = 1, k = 0, n = --kk;
			while(k <= N && C < K) {
				K -= C;
				n++;
				k++;
				C = (C*n/k);
			}
			if(k > N) {
				bw.write("-1");
				bw.close();
				return;
			}
			for(int i=0;i<N-k;i++) ans += 'a';
			ans += 'z';
			N -= (N-k);
			M--;
		}
		for(int i=0;i<N;i++) ans += 'a';
		for(int i=0;i<kk;i++) ans += 'z';
		bw.write(ans);
		
		
		
		bw.close();
	}

}