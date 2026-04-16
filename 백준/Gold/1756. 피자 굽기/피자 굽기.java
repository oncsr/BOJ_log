import java.util.*;
import java.io.*;

public class Main {
	static StringTokenizer st;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static int nextInt() { return Integer.parseInt(st.nextToken()); }
	static void newLine() throws Exception { st = new StringTokenizer(br.readLine()); }
	
	public static void main(String[] args) throws Exception {

		newLine();
		int D = nextInt(), N = nextInt();
		int[] oven = new int[D+1];
		newLine();
		for(int i=1;i<=D;i++) oven[i] = nextInt();
		int[] min = new int[D+2];
		min[1] = oven[1];
		for(int i=2;i<=D;i++) min[i] = Math.min(min[i-1], oven[i]);
		
		newLine();
		int idx = D+1;
		while(N-- > 0 && idx > 0) {
			int a = nextInt();
			int pi = idx;
			while(idx > 0 && min[idx] < a) idx--;
			if(idx == pi) idx--;
		}
		bw.write(idx+"\n");
		
		bw.close();
	}

}