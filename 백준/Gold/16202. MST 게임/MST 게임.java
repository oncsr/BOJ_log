import java.util.*;
import java.io.*;

class Edge{
	int x;
	int y;
	int cost;
	Edge(int x, int y, int cost){
		this.x = x;
		this.y = y;
		this.cost = cost;
	}
}

public class Main {
	static StringTokenizer st;
	static int nextInt() { return Integer.parseInt(st.nextToken()); }
	
	static int[] R = new int[1001];
	static int find(int x) { return x==R[x] ? x : (R[x]=find(R[x])); }
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		st = new StringTokenizer(br.readLine());

		int N = nextInt(), M = nextInt(), K = nextInt();
		
		Edge[] E = new Edge[M];
		for(int i=0,a,b;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			a = nextInt();
			b = nextInt();
			E[i] = new Edge(a,b,i+1);
		}
		Arrays.sort(E, (a,b) -> a.cost - b.cost);
		
		for(int i=0;i<K;i++) {
			
			for(int j=1;j<=N;j++) R[j] = j;
			int res = 0, cnt = 0;
			for(int j=i;j<M;j++) {
				int x = find(E[j].x), y = find(E[j].y);
				if(x==y) continue;
				res += E[j].cost;
				R[x] = y;
				cnt++;
			}
			if(cnt != N-1) {
				for(;i<K;i++) bw.write("0 ");
				bw.close();
				return;
			}
			bw.write(res+ " ");
			
		}
		
		bw.close();
	}

}