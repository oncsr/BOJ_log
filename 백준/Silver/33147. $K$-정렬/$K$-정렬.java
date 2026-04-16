import java.util.*;
import java.io.*;

class Main
{
	public static int gcd(int a, int b) {
		if(a == 0) return b;
		if(b == 0) return a;
		if(a > b) return a%b==0 ? b : gcd(b,a%b);
		return b%a==0 ? a : gcd(a,b%a);
	}
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		
		int G = gcd(N,K);
		
		int[][] A = new int[G][N/G];
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<N;i++) {
			int a = Integer.parseInt(st.nextToken());
			A[i%G][i/G] = a;
		}
		
		for(int i=0;i<G;i++) Arrays.sort(A[i]);
		for(int i=1;i<N;i++) {
			if(A[(i-1)%G][(i-1)/G] > A[i%G][i/G]) {
				bw.write("NO");
				bw.close();
				return;
			}
		}
		bw.write("YES");
		
		bw.flush();
		bw.close();
	}
}