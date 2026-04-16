import java.util.*;
import java.io.*;

class Main {
	
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
	
	static class Node{
		int cnt, child;
		boolean end;
		Node[] next;
		Node(){
			cnt = 0;
			child = 0;
			end = false;
			next = new Node[26];
		}
	}
	
	static class Trie{
		Node root;
		long ans;
		Trie(){
			root = new Node();
			ans = 0;
		}
		void insert(char[] A) {
			Node now = root;
			for(char i:A) {
				now.cnt++;
				if(now.next[i-'a'] == null) {
					now.child++;
					now.next[i-'a'] = new Node();
				}
				now = now.next[i-'a'];
			}
			now.end = true;
		}
		void DFS() {
			Node now = root;
			for(int i=0;i<26;i++) if(now.next[i] != null) dfs(now.next[i], 1);
		}
		void dfs(Node n, int d) {
			if(n.end) ans += d;
			int nextD = d + (n.child>1 || n.end ? 1 : 0);
			for(int i=0;i<26;i++) if(n.next[i] != null) dfs(n.next[i], nextD);
		}
	}
	
	static int N;
	static Trie trie;
	
	public static void main(String[] args) throws Exception {
		
		String temp;
		while((temp = br.readLine()) != null) {
			N = Integer.parseInt(temp);
			ready();
			solve();
		}
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		trie = new Trie();

	}
	
	static void solve() throws Exception{
		
		for(int i=0;i<N;i++) trie.insert(nextToken().toCharArray());
		trie.DFS();
		double res = Math.round((double)trie.ans * 100.0 / N);
		bw.write(String.format("%.2f", res/100) + "\n");
		
	}
	
}