import java.util.*;
import java.io.*;

public class Main {
	static StringTokenizer st;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static int nextInt() { return Integer.parseInt(st.nextToken()); }
	static void newLine() throws Exception { st = new StringTokenizer(br.readLine()); }
	
	public static void main(String[] args) throws Exception {

		int N = Integer.parseInt(br.readLine());
		if(N < 3) {bw.write("0");bw.close();return;}
		newLine();
		int[] A = new int[N];
		for(int i=0;i<N;i++) A[i] = nextInt();
		
		int ans = (int)1e9;
		for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++) {
			int d = A[1]+j - (A[0]+i), prev = A[1] + j;
			int res = (i == 0 ? 0 : 1) + (j == 0 ? 0 : 1);
			for(int k=2;k<N;k++) {
				if(A[k] - prev != d) {
					if(A[k] + 1 - prev == d) {prev = A[k]+1;res++;}
					else if(A[k] -1 -prev == d) {prev = A[k]-1;res++;}
					else {res=(int)1e9 + 1;break;}
				}
				else prev = A[k];
			}
			ans = Math.min(ans, res);
		}
		bw.write((ans==(int)1e9 ? -1 : ans) + "\n");
		
		bw.close();
	}

}