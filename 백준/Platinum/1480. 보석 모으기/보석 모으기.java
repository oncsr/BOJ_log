import java.util.*;
import java.io.*;

class Main
{
	static int N, M, C;
	static int[] A;
	static int[] D;
	static int ans = 0;
	
	public static void sol(int pos, int K, int g) {
		if(g > C) return;
		if(pos == N) {
			D[K] = 1;
			return;
		}
		sol(pos+1, K|(1<<pos), g+A[pos]);
		sol(pos+1, K, g);
	}
	
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));


		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		
		A = new int[N];
		D = new int[(1<<N)];
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<N;i++) A[i] = Integer.parseInt(st.nextToken());
		sol(0,0,0);
		
        for(int i=0;i<(1<<N);i++) {
            if(D[i] == 0) continue;
            for(int j=0;j<(1<<N);j++){
                if((j|i) != j) continue;
                if(D[j-i] == 0) continue;
                if(D[j] == 0) D[j] = D[i] + D[j-i];
                else 	D[j] = Math.min(D[j], D[i]+D[j-i]);
            }
        }
		
		for(int i=0;i<(1<<N);i++) {
			if(D[i] == 0 || D[i] > M) continue;
			int cnt = 0;
			for(int j=0;j<N;j++) {
				if((i&(1<<j)) != 0) cnt++;
			}
			ans = Math.max(ans, cnt);
		}
		bw.write(ans+"\n");
		
		bw.flush();
		bw.close();
	}
}