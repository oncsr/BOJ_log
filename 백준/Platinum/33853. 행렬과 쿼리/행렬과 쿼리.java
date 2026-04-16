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
	
	static final long MOD = (int)1e9 + 9;
	
	static class Matrix {
		long[][] arr;
		int row, col;
		
		Matrix(){
			arr = new long[3][3];
			row = 2;
			col = 2;
		}
		
		Matrix(int inf){
			this();
			this.arr[0][0] = inf;
		}
		
		Matrix(Matrix mat){
			this();
			this.row = mat.row;
			this.col = mat.col;
			for(int i=0;i<this.row;i++) for(int j=0;j<this.col;j++) {
				this.arr[i][j] = mat.arr[i][j];
			}
		}
		
		Matrix merge(Matrix other) {
			if(this.arr[0][0] == -1) return new Matrix(-1);
			if(other.arr[0][0] == -1) return new Matrix(-1);
			if(this.arr[0][0] == -2) return new Matrix(other);
			if(other.arr[0][0] == -2) return new Matrix(this);
			if(this.col != other.row) return new Matrix(-1);
			
			Matrix ret = new Matrix();
			ret.row = this.row;
			ret.col = other.col;
			for(int i=0;i<ret.row;i++) for(int j=0;j<ret.col;j++) {
				for(int k=0;k<this.col;k++) {
					ret.arr[i][j] += this.arr[i][k] * other.arr[k][j];
					ret.arr[i][j] %= MOD;
				}
			}
			return ret;
		}
		
		void addRow() {
			row++;
		}
		
		void deleteRow() {
			for(int i=0;i<col;i++) arr[2][i] = 0;
			row--;
		}
		
		void addCol() {
			col++;
		}
		
		void deleteCol() {
			for(int i=0;i<row;i++) arr[i][2] = 0;
			col--;
		}
		
		void change(int x, int y, int val) {
			arr[x][y] = val;
		}
	}
	
	static class SegmentTree {
		int size;
		Matrix[] seg;
		
		SegmentTree(int size){
			seg = new Matrix[size*4];
			init(1,size,1);
			this.size = size;
		}
		
		void init(int s, int e, int n) {
			if(s == e) {
				seg[n] = new Matrix();
				return;
			}
			int m = (s+e)>>1;
			init(s,m,n*2);
			init(m+1,e,n*2+1);
			seg[n] = new Matrix();
		}
		
		long query(int s, int e, int l, int r, int i, int j, int n) {
			Matrix ret = get(1,size,l,r,1);
			if(ret.arr[0][0] == -1) return -1;
			return ret.arr[i-1][j-1];
		}
		
		Matrix get(int s, int e, int l, int r, int n) {
			if(l>r || l>e || r<s) return new Matrix(-2);
			if(l<=s && e<=r) return seg[n];
			int m = (s+e)>>1;
			return get(s,m,l,r,n*2).merge(get(m+1,e,l,r,n*2+1));
		}
		
		void addRow(int s, int e, int i, int n) {
			if(s == e) {
				seg[n].addRow();
				return;
			}
			int m = (s+e)>>1;
			if(i <= m) addRow(s,m,i,n*2);
			else addRow(m+1,e,i,n*2+1);
			seg[n] = seg[n*2].merge(seg[n*2+1]);
		}
		
		void deleteRow(int s, int e, int i, int n) {
			if(s == e) {
				seg[n].deleteRow();
				return;
			}
			int m = (s+e)>>1;
			if(i <= m) deleteRow(s,m,i,n*2);
			else deleteRow(m+1,e,i,n*2+1);
			seg[n] = seg[n*2].merge(seg[n*2+1]);
		}
		
		void addCol(int s, int e, int i, int n) {
			if(s == e) {
				seg[n].addCol();
				return;
			}
			int m = (s+e)>>1;
			if(i <= m) addCol(s,m,i,n*2);
			else addCol(m+1,e,i,n*2+1);
			seg[n] = seg[n*2].merge(seg[n*2+1]);
		}
		
		void deleteCol(int s, int e, int i, int n) {
			if(s == e) {
				seg[n].deleteCol();
				return;
			}
			int m = (s+e)>>1;
			if(i <= m) deleteCol(s,m,i,n*2);
			else deleteCol(m+1,e,i,n*2+1);
			seg[n] = seg[n*2].merge(seg[n*2+1]);
		}
		
		void change(int s, int e, int i, int j, int k, int v, int n) {
			if(s == e) {
				seg[n].change(j-1, k-1, v);
				return;
			}
			int m = (s+e)>>1;
			if(i <= m) change(s,m,i,j,k,v,n*2);
			else change(m+1,e,i,j,k,v,n*2+1);
			seg[n] = seg[n*2].merge(seg[n*2+1]);
		}
		
	}
	
	static SegmentTree tree;
	static int N, Q;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
		
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		N = nextInt();
		tree = new SegmentTree(N);
		
	}
	
	static void solve() throws Exception {
		
		for(Q = nextInt();Q-->0;) {
			int op = nextInt();
			
			if(op == 1) {
				int l = nextInt(), r = nextInt(), i = nextInt(), j = nextInt();
				bw.write(tree.query(1,N,l,r,i,j,1) + "\n");
			}
			else if(op == 2) {
				int i = nextInt();
				tree.addRow(1, N, i, 1);
			}
			else if(op == 3) {
				int i = nextInt();
				tree.deleteRow(1, N, i, 1);
			}
			else if(op == 4) {
				int i = nextInt();
				tree.addCol(1, N, i, 1);
			}
			else if(op == 5) {
				int i = nextInt();
				tree.deleteCol(1, N, i, 1);
			}
			else {
				int i = nextInt(), j = nextInt(), k = nextInt(), v = nextInt();
				tree.change(1,N,i,j,k,v,1);
			}
		}
		
	}
	
}