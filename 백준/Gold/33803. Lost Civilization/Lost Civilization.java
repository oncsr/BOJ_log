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
	
	static int N;
	static int[][] info;
	static List<Integer>[] cnt;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		info = new int[N][2];
		cnt = new List[N+1];
		for(int i=0;i<=N;i++) cnt[i] = new ArrayList<>();
		for(int i=0;i<N;i++) {
			info[i][0] = nextInt();
			info[i][1] = i+1;
			cnt[info[i][0]].add(i+1);
		}
		
	}
	
	static void solve() throws Exception {
		
		if(!valid()) {
			bw.write("-1");
			return;
		}
		List<int[]> res = new ArrayList<>();
		for(int i=1;i<=N;i++) {
			if(cnt[i].isEmpty()) {
				for(int j=1;j<cnt[i-1].size();j++) {
					res.add(new int[] {cnt[i-1].get(j-1), cnt[i-1].get(j)});
				}
				break;
			}
			for(int j=0;j<cnt[i].size();j++) {
				res.add(new int[] {cnt[i].get(j), cnt[i-1].get(j)});
			}
			for(int j=cnt[i].size();j<cnt[i-1].size();j++) {
				res.add(new int[] {cnt[i].get(cnt[i].size()-1), cnt[i-1].get(j)});
			}
		}
		
		for(int[] e:res) bw.write(e[0] + " " + e[1] + "\n");
		
	}
	
	static boolean valid() {
		if(cnt[0].size() == 0) return false;
		int i;
		for(i=0;!cnt[i].isEmpty();i++) {
			if(cnt[i].size() < cnt[i+1].size()) return false;
			while(cnt[i].size()-1 >= cnt[i+1].size()+1) {
				cnt[i+1].add(cnt[i].remove(cnt[i].size()-1));
			}
		}
		if(i>1 && cnt[i-1].size() == 1 && cnt[i-2].size() == 1) return false;
		if(i>1 && cnt[i-1].size() > cnt[i-2].size()) return false;
		return true;
	}
	
}