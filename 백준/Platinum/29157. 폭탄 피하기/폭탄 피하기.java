import java.util.*;
import java.io.*;

class Main {
	
	// IO field
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st = new StringTokenizer("");

	static void nextLine() throws Exception {st = new StringTokenizer(br.readLine());}
	static int nextInt() throws Exception {
		if(!st.hasMoreTokens()) nextLine();
		return Integer.parseInt(st.nextToken());
	}
	static long nextLong() throws Exception {
		if(!st.hasMoreTokens()) nextLine();
		return Long.parseLong(st.nextToken());
	}
	static void bwEnd() throws Exception {bw.flush();bw.close();}
	
	// Additional field
	
	static final long mod = (long)1e9 + 7;
	static int N, M, K;
	static int[][] bomb;
	
	static long[] f;
    static long ans=0;
	
	public static void main(String[] args) throws Exception {
			
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{
		
		f = new long[2000001];
		f[0] = 1;
		for(int i=1;i<=2000000;i++) f[i] = (f[i-1] * i) % mod;
		
		N = nextInt();
		M = nextInt();
		K = nextInt();
		bomb = new int[K][];
		for(int i=0;i<K;i++) bomb[i] = new int[] {nextInt(), nextInt()};
		Arrays.sort(bomb, (a,b) -> {
		  if(a[0]==b[0]) return a[1]-b[1];
		  return a[0]-b[0];
		  });
		
	}
	
	static void solve() throws Exception{
		
		bck(0,0,0,0,1);
		
		bw.write(ans + "\n");
		
	}
    
    static void bck(int cnt, int pos, int px, int py, long res){
        if(pos == K){
            int dx = N-px, dy = M-py; 
			res = (res * comb(dx+dy, dx)) % mod;
			if(cnt%2 != 0) ans=(ans+mod-res)%mod;
            else ans=(ans+res)%mod;
            return;
        }
        bck(cnt, pos+1, px, py, res);
        int x = bomb[pos][0], y = bomb[pos][1];
				if(x < px || y < py)
					return;
				int dx = x-px, dy = y-py;
				res = (res * comb(dx+dy, dx)) % mod;
				px = x;
				py = y;
        bck(cnt+1, pos+1, px, py, res);
    }
	
	static long comb(int n, int k) {
		return f[n] * power(f[k], mod-2) % mod * power(f[n-k], mod-2) % mod;
	}
	
	static long power(long x, long p) {
		if(p == 0) return 1;
		if(p == 1) return x%mod;
		long half = power(x, p>>1) % mod;
		half = (half * half)%mod;
		if(p%2 == 0) return half;
		return half*x%mod;
	}
	
}