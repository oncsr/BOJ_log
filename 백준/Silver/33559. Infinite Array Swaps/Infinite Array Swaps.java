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

    static int N;
    static int[] A, B, S;
    static Map<Integer, Queue<Integer>> M;
    static boolean[] clear;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{

        M = new TreeMap<>();
        N = Integer.parseInt(br.readLine());
        A = new int[N];
        B = new int[N];
        S = new int[N];
        clear = new boolean[N];
        
        nextLine();
        for(int i=0;i<N;i++) A[i] = nextInt();
        nextLine();
        for(int i=0;i<N;i++) B[i] = nextInt();
		
	}
	
	static void solve() throws Exception{

        for(int i=0;i<N;i++) {
            if(M.get(A[i]) == null) M.put(A[i], new LinkedList<>());
            M.get(A[i]).add(i);
        }
        
        List<Integer> temp = new ArrayList<>();
        int ans = 0;
        for(int i=0;i<N;i++){
            if(M.get(B[i]) == null || M.get(B[i]).isEmpty()) {
                temp.add(B[i]);
            }
            else{
                int j = M.get(B[i]).poll();
                S[j] = B[i];
                clear[j] = true;
                ans++;
            }
        }
        
        int x = 0;
        for(int i:temp){
            while(clear[x]) x++;
            S[x++] = i;
        }
        
        bw.write(ans + "\n");
        for(int i:A) bw.write(i + " ");
        bw.write("\n");
        for(int i:S) bw.write(i + " ");
        bw.write("\n");
        
		
	}
	
}