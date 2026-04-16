import java.util.*;
import java.io.*;


class Main {
	
	// IO field
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;

	static void nextLine() throws Exception {st = new StringTokenizer(br.readLine());}
	static int nextInt() {return Integer.parseInt(st.nextToken());}
	static long nextLong() {return Long.parseLong(st.nextToken());}
	static void bwEnd() throws Exception {bw.flush();bw.close();}
	
	// Additional field

	static int L, C;
	static List<Character> A, B;
	static char[] ans;
	static List<String> res;
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		A = new ArrayList<>();
		B = new ArrayList<>();
		nextLine();
		L = nextInt();
		C = nextInt();
		nextLine();
		for(int i=0;i<C;i++) {
			char a = st.nextToken().charAt(0);
			if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u') A.add(a);
			else B.add(a);
		}
		Collections.sort(A);
		Collections.sort(B);
		ans = new char[L];
		res = new ArrayList<>();
		
	}
	
	static void solve() throws Exception{
		
		bck(0,0,0,0);
		Collections.sort(res);
		for(String i:res) bw.write(i + "\n");
		
	}
	
	static void bck(int a, int b, int la, int lb) {
		
		if(a+b > 1 && ans[a+b-1] < ans[a+b-2]) return;
		if(a+b == L) {
			if(a < 1 || b < 2) return;
			String temp = "";
			for(char i:ans) temp += i;
			res.add(temp);
			return;
		}
		
		for(int i=la;i<A.size();i++) {
			ans[a+b] = A.get(i);
			bck(a+1,b,i+1,lb);
			ans[a+b] = ' ';
		}
		
		for(int i=lb;i<B.size();i++) {
			ans[a+b] = B.get(i);
			bck(a,b+1,la,i+1);
			ans[a+b] = ' ';
		}
	}
	
}