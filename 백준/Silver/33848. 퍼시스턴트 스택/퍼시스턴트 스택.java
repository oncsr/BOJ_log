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
	
	static class PersistentStack{
		Stack<Integer> recentOperations;
		Stack<Integer> stack;
		
		PersistentStack(){
			recentOperations = new Stack<>();
			stack = new Stack<>();
		}
		
		void push(int x) {
			stack.push(x);
			recentOperations.add(x);
		}
		
		void pop() {
			recentOperations.add(-stack.pop());
		}
		
		void rollback(int x) {
			while(x-->0) {
				int v = recentOperations.pop();
				if(v < 0) stack.push(-v);
				else stack.pop();
			}
		}
		
		int size() {
			return stack.size();
		}
		
		int top() {
			return stack.isEmpty() ? -1 : stack.peek();
		}
	}
	
	static PersistentStack pStack;
	static int Q;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		pStack = new PersistentStack();
		
	}
	
	static void solve() throws Exception {
		
		for(Q = nextInt();Q-->0;) {
			int op = nextInt();
			
			if(op == 1) pStack.push(nextInt());
			else if(op == 2) pStack.pop();
			else if(op == 3) pStack.rollback(nextInt());
			else if(op == 4) bw.write(pStack.size() + "\n");
			else bw.write(pStack.top() + "\n");
			
		}
		
	}
	
}