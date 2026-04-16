import java.util.*;
import java.io.*;

class Main
{
	
	static ArrayList<Integer>[] V;
	static int ans = 0;
	public static int dfs(int n) {
		int mx1 = 0, mx2 = 0;
		for(int i:V[n]) {
			int g = dfs(i) + 1;
			if(g > mx1) {
				mx2 = mx1;
				mx1 = g;
			}
			else if(g > mx2) mx2 = g;
		}
		ans = Math.max(ans,  mx1 + mx2);
		return mx1;
		
	}
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int N = Integer.parseInt(br.readLine());
		
		int[] C = new int[N+1];
		int vertex = 0;
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=1;i<=N;i++) {
			C[i] = Integer.parseInt(st.nextToken());
			vertex += C[i];
			C[i] = vertex;
		}
		
		V = new ArrayList[vertex+1];
		
		for(int i=0;i<=vertex;i++) V[i] = new ArrayList<>();
		
		for(int i=1;i<=N;i++) {
			int l = C[i-1] + 1, r = C[i];
			
			int pl = i==1 ? 0 : C[i-2] + 1;
			int pr = C[i-1];
			int p = pl;
			for(int j=l;j<=r;j++) {
				V[p].add(j);
				p++;
				if(p > pr) p = pl;
			}
		}
		dfs(0);
		bw.write(ans+"\n");
		
		bw.flush();
		bw.close();
	}
}