import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int N = Integer.parseInt(br.readLine());
		
		int[] A = new int[N+1];
		bw.write("? 1 * 2\n");
		bw.flush();
		
		int a = 1, b = 0, c = 0, d = 0;
		A[2] = br.readLine().equals("+") ? 0 : 1;
		if(A[2] == 0) b = 2;
		else c = 2;
		for(int i=3;i<=N;i++) {
			bw.write("? "+(i-1) + " * "+i+"\n");
			bw.flush();
			A[i] = br.readLine().equals("+") ? A[i-1] : A[i-1]^1;
			if(A[i] == 0) b = i;
			else {
				if(c == 0) c = i;
				else d = i;
			}
		}
		
		if(b == 0) {
			bw.write("? "+c+" + "+d+"\n");
			bw.flush();
			if(br.readLine().equals("+")) {
				bw.write("! ");
				for(int i=1;i<=N;i++) bw.write(A[i]==0 ? "- " : "+ ");
				bw.write("\n");
				bw.flush();
			}
			else {
				bw.write("! ");
				for(int i=1;i<=N;i++) bw.write(A[i]==0 ? "+ " : "- ");
				bw.write("\n");
				bw.flush();
			}
		}
		else {
			bw.write("? "+a+" + "+b+"\n");
			bw.flush();
			if(br.readLine().equals("+")) {
				bw.write("! ");
				for(int i=1;i<=N;i++) bw.write(A[i]==0 ? "+ " : "- ");
				bw.write("\n");
				bw.flush();
			}
			else {
				bw.write("! ");
				for(int i=1;i<=N;i++) bw.write(A[i]==0 ? "- " : "+ ");
				bw.write("\n");
				bw.flush();
			}
			
		}
		
		bw.close();
	}

}