import java.util.*;
import java.io.*;

class Node{
	String s;
	int v;
	Node(String s, int v){
		this.s = s;
		this.v = v;
	}
}

public class Main {
	static StringTokenizer st;
	static int nextInt() { return Integer.parseInt(st.nextToken()); }

	static int N;
	static String[] A;
	static int[] seg = new int[262145];
	
	static void upt(int s, int e, int i, int n) {
		if(s==e) { seg[n]++; return; }
		int m=(s+e)>>1;
		if(i<=m) upt(s,m,i,n*2);
		else upt(m+1,e,i,n*2+1);
		seg[n] = seg[n*2] + seg[n*2+1];
	}
	
	static int find(int s, int e, int l, int r, int n) {
		if(l>r || l>e || r<s) return 0;
		if(l<=s && e<=r) return seg[n];
		int m=(s+e)>>1;
		return find(s,m,l,r,n*2) + find(m+1,e,l,r,n*2+1);
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int N = Integer.parseInt(br.readLine());
		A = new String[N];
		for(int i=0;i<N;i++) A[i] = br.readLine();
		Arrays.sort(A);
		
		Node[] arr = new Node[N];
		for(int i=0;i<N;i++) {
			String temp = "";
			for(int j=A[i].length()-1;j>=0;j--) temp += A[i].charAt(j);
			arr[i] = new Node(temp,i);
		}
		Arrays.sort(arr, (a,b) -> (a.s).compareTo(b.s));
		long ans = 0;
		for(Node i:arr) {
			ans += find(0,N-1,i.v,N-1,1);
			upt(0,N-1,i.v,1);
		}
		bw.write(ans+"\n");
		
		bw.close();
	}

}