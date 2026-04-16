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

    static int N, M, U, V;
    static char[][] A, S;
    static String com;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{

        nextLine();
        N = nextInt();
        M = nextInt();
        nextLine();
        U = nextInt();
        V = nextInt();
        
        A = new char[U][V];
        S = new char[N][M];
        for(int i=0;i<U;i++) A[i] = br.readLine().toCharArray();
        
        com = br.readLine();
		
	}
	
	static void solve() throws Exception{

        if(com.equals("clamp-to-edge")) clamp_to_edge();
        if(com.equals("repeat")) repeat();
        if(com.equals("mirrored-repeat")) mirrored_repeat();
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++) bw.write(S[i][j]);
            bw.write("\n");
        }
		
	}
	
	static void clamp_to_edge(){
	    for(int i=0;i<N;i++) for(int j=0;j<M;j++){
	        if(i >= U && j >= V) S[i][j] = A[U-1][V-1];
	        else if(i >= U) S[i][j] = A[U-1][j];
	        else if(j >= V) S[i][j] = A[i][V-1];
	        else S[i][j] = A[i][j];
	    }
	}
	
	static void repeat(){
	    for(int i=0;i<N;i++) for(int j=0;j<M;j++) S[i][j] = A[i%U][j%V];
	}
	
	static void mirrored_repeat(){
	    for(int i=0;i<N;i++) for(int j=0;j<M;j++){
	        if(i % (2*U) < U && j % (2*V) < V) S[i][j] = A[i % (2*U)][j % (2*V)];
	        else if(i % (2*U) < U) S[i][j] = A[i % (2*U)][2*V - (j % (2*V)) - 1];
	        else if(j % (2*V) < V) S[i][j] = A[2*U - (i % (2*U)) - 1][j % (2*V)];
	        else S[i][j] = A[2*U - (i % (2*U)) - 1][2*V - (j % (2*V)) - 1];
	    }
	}
	
	
}