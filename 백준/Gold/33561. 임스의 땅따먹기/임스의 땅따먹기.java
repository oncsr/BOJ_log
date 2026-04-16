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

    static int N, K;
    static int[][] A, Z;
    static int[] B, S;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{

        N = Integer.parseInt(br.readLine());
        A = new int[N+1][N+1];
        Z = new int[N+1][N+1];
        for(int i=1;i<=N;i++){
            nextLine();
            for(int j=1;j<=N;j++){
                int a = nextInt();
                A[i][j] = a + A[i-1][j] + A[i][j-1] - A[i-1][j-1];
                Z[i][j] = (a > 0 ? 0 : 1) + Z[i-1][j] + Z[i][j-1] - Z[i-1][j-1];
            }
        }
        
        
        K = Integer.parseInt(br.readLine());
        B = new int[K];
        S = new int[K+1];
        nextLine();
        for(int i=0;i<K;i++) B[i] = -nextInt();
		
	}
	
	static void solve() throws Exception{

        Arrays.sort(B);
        for(int i=1;i<=K;i++) S[i] = S[i-1] + -B[i-1];
        
        int ans = 0;
        for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) for(int k=0;i+k<=N && j+k<=N;k++){
            int val = A[i+k][j+k] - A[i-1][j+k] - A[i+k][j-1] + A[i-1][j-1];
            int zero = Z[i+k][j+k] - Z[i-1][j+k] - Z[i+k][j-1] + Z[i-1][j-1];
            
            if(zero > K) break;
            ans = Math.max(ans, val + S[zero]);
        }
        bw.write(ans + "\n");
		
	}
	
}