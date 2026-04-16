import java.util.*;
import java.io.*;

public class Main {
	static StringTokenizer st;
	static int nextInt() { return Integer.parseInt(st.nextToken()); }
	
	static int[] R;
	static int[] C;
	static int find(int x) { return x==R[x] ? x : (R[x]=find(R[x])); }
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int N = Integer.parseInt(br.readLine());

		long[] SS = new long[200001];
		for(int i=1;i<=200000;i++) SS[i] = SS[i-1] + (long)i*((long)i+1)/2;
		
		R = new int[N+1];
		C = new int[N+1];
		for(int i=1;i<=N;i++) { R[i] = i; C[i] = 1; }
		
		long A = 0, B = 0;
		for(int i=1;i<N;i++) {
			int a = Integer.parseInt(br.readLine());
			int x = find(a), y = find(a+1);
			A += (long)C[x] * C[y];
			B += SS[C[x]+C[y]-1] - SS[C[x]-1] - SS[C[y]-1];
			C[y] += C[x];
			R[x] = y;
			bw.write(A+" "+B+"\n");
		}
		
		bw.close();
	}

}