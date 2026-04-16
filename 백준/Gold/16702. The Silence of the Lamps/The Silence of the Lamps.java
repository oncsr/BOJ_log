import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int[] C = new int[1000001];
		for(int a=1;a<=100;a++) {
			for(int b=a+1;b<=1000;b++) {
				if(a*b > 1000000) break;
				for(int c=b+1;c<=1000000;c++) {
					if(a*b*c > 1000000) break;
					C[a*b*c]++;
				}
			}
		}
		int[] S = new int[1000001];
		int g = 0;
		for(int i=1;i<=1000000;i++) {
			g += C[i];
			S[i] = g;
		}
		
		int T = Integer.parseInt(br.readLine());
		while(T-->0) {
			int N = Integer.parseInt(br.readLine());
			bw.write(S[N]+"\n");
		}
		
		bw.flush();
		bw.close();
	}

}
