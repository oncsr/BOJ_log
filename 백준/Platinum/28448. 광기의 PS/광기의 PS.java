import java.util.*;
import java.io.*;

class Node{
	int lim;
	int val;
	int k;
	Node(int lim, int val, int k){
		this.lim = lim;
		this.val = val;
		this.k = k;
	}
}

public class Main {
	static StringTokenizer st;
	static int nextInt() { return Integer.parseInt(st.nextToken()); }

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		st = new StringTokenizer(br.readLine());

		int N = nextInt(), L = nextInt();
		long ans = 0;
		
		ArrayList<Node> arr = new ArrayList<>();
		
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			int k = nextInt(), t = nextInt();
			if(t > 5) arr.add(new Node(L-k*t,k*t-5*k,k));
			ans+=t;
		}
		Collections.sort(arr, (a,b) -> (a.val-b.lim)- (b.val-a.lim) );
		int v = 0;
		for(Node i:arr) {
			if(v > i.lim) {
				ans += v-i.lim;
				v = i.lim;
			}
			v += i.val;
		}
		bw.write(ans+"\n");
		
		bw.close();
	}

}