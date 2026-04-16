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

	static long[] seg = new long[262145];
	static long[] arr = new long[100001];
	
	static void prop(int s, int e, int n) {
		if(seg[n] == 0) return;
		if(s == e) arr[s] += seg[n];
		else {
			seg[n*2] += seg[n];
			seg[n*2+1] += seg[n];
		}
		seg[n] = 0;
	}
	
	static void upt(int s, int e, int l, int r, long v, int n) {
		if(l>r || l>e || r<s) return;
		prop(s,e,n);
		if(l<=s && e<=r) {
			if(s==e) arr[s] += v;
			else {
				seg[n*2] += v;
				seg[n*2+1] += v;
			}
			return;
		}
		int m=(s+e)>>1;
		upt(s,m,l,r,v,n*2);
		upt(m+1,e,l,r,v,n*2+1);
	}
	
	static long find(int s, int e, int i, int n) {
		prop(s,e,n);
		if(s==e) return arr[s];
		int m=(s+e)>>1;
		if(i <= m) return find(s,m,i,n*2);
		return find(m+1,e,i,n*2+1);
	}
	
	public static void main(String[] args) throws Exception {

		nextLine();
		int N = nextInt();
		nextLine();
		for(int i=1;i<=N;i++) arr[i] = nextInt();
		
		nextLine();
		int Q = nextInt();
		while(Q-- > 0) {
			nextLine();
			int o = nextInt();
			if(o == 1) {
				int l = nextInt(), r = nextInt(), v = nextInt();
				upt(1,N,l,r,v,1);
			}
			else {
				int x = nextInt();
				bw.write(find(1,N,x,1)+"\n");
			}
		}
		
		
		bwEnd();
	}

}