import java.util.*;
import java.io.*;

public class Main {
	
	// IO field
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st = new StringTokenizer("");

	static void nextLine() throws Exception {st = new StringTokenizer(br.readLine());}
	static String nextToken() throws Exception {
		while(!st.hasMoreTokens()) nextLine();
		return st.nextToken();
	}
	static int nextInt() throws Exception { return Integer.parseInt(nextToken()); }
	static long nextLong() throws Exception { return Long.parseLong(nextToken()); }
	static double nextDouble() throws Exception { return Double.parseDouble(nextToken()); }
	static void bwEnd() throws Exception {bw.flush();bw.close();}
	
	// Additional field
	
	static class Student {
		String name;
		int score, risk, cost, grade;
		Student(String name, int score, int risk, int cost){
			this.name = name;
			this.score = score;
			this.risk = risk;
			this.cost = cost;
			this.grade = score*score*score / (cost*(risk+1));
		}
	}
	
	static int N;
	static Student[] A; 
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		A = new Student[N];
		for(int i=0;i<N;i++) A[i] = new Student(nextToken(), nextInt(), nextInt(), nextInt());
		
	}
	
	static void solve() throws Exception {
		
		Arrays.sort(A, (a,b) -> {
			if(a.grade == b.grade) {
				if(a.cost == b.cost) return a.name.compareTo(b.name);
				return a.cost-b.cost;
			}
			return b.grade-a.grade;
		});
		bw.write(A[1].name + "\n");
		
	}
	
}