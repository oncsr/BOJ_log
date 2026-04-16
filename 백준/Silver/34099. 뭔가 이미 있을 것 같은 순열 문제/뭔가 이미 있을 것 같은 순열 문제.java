import java.io.*;
import java.util.*;

class IOController {
	BufferedReader br;
	BufferedWriter bw;
	StringTokenizer st;

	public IOController() {
		br = new BufferedReader(new InputStreamReader(System.in));
		bw = new BufferedWriter(new OutputStreamWriter(System.out));
		st = new StringTokenizer("");
	}

	String nextLine() throws Exception {
		String line = br.readLine();
		st = new StringTokenizer(line);
		return line;
	}

	String nextToken() throws Exception {
		while (!st.hasMoreTokens())
			nextLine();
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

	void close() throws Exception {
		bw.flush();
		bw.close();
	}

	void write(String content) throws Exception {
		bw.write(content);
	}

}

public class Main {

	static IOController io;

	//

	static int N, K;

	public static void main(String[] args) throws Exception {

		io = new IOController();

		for(int T=io.nextInt();T-->0;) {
			N = io.nextInt();
			K = io.nextInt();
			if(K > 1) {
				for(int i=1;i<=N;i++) io.write(i + " ");
			}
			else {
				if(N <= 3) io.write("-1");
				else {
					for(int i=2;i<=N;i+=2) io.write(i + " ");
					for(int i=1;i<=N;i+=2) io.write(i + " ");
				}
			}
			io.write("\n");
		}

		io.close();

	}

}