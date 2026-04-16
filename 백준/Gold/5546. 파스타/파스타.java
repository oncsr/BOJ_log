import java.util.*;
import java.io.*;

public class Main {
	static StringTokenizer st;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static int nextInt() { return Integer.parseInt(st.nextToken()); }
	static void newLine() throws Exception { st = new StringTokenizer(br.readLine()); }
	
	static int[] r = new int[10001];
	static int f(int x) {return x==r[x] ? x : (r[x]=f(r[x]));}
	
	public static void main(String[] args) throws Exception {

		newLine();
		int N = nextInt(), K = nextInt();
		int[] day = new int[N+1];
		for(int i=1;i<=K;i++) {
			newLine();
			int a = nextInt(), b = nextInt();
			day[a] = b;
		}
		
		int[][] D = new int[3][3];
		int mod = 10000;
		if(day[1] == 0 && day[2] == 0) {
			for(int i=0;i<3;i++) for(int j=0;j<3;j++) D[i][j] = 1;
		}
		else if(day[1] == 0) {
			for(int i=0;i<3;i++) D[i][day[2]-1] = 1;
		}
		else if(day[2] == 0) {
			for(int i=0;i<3;i++) D[day[1]-1][i] = 1;
		}
		else D[day[1]-1][day[2]-1] = 1;
		
		
		for(int n=3;n<=N;n++) {
			int[][] ND = new int[3][3];
			if(day[n] == 0) {
				for(int i=0;i<3;i++) for(int j=0;j<3;j++) {
					ND[i][j] = D[0][i] + D[1][i] + D[2][i];
					if(i == j) ND[i][j] -= D[i][i];
					ND[i][j] %= mod;
				}
			}
			else {
				day[n]--;
				for(int i=0;i<3;i++) {
					ND[i][day[n]] = D[0][i] + D[1][i] + D[2][i];
					if(i == day[n]) ND[i][day[n]] -= D[i][i];
					ND[i][day[n]] %= mod;
				}
			}
			for(int i=0;i<3;i++) for(int j=0;j<3;j++) D[i][j] = ND[i][j];
		}
		int ans = 0;
		for(int i=0;i<3;i++) for(int j=0;j<3;j++) {
			ans += D[i][j];
		}
		bw.write((ans%mod)+"\n");
		
		bw.close();
	}

}