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
    static int[] D;
    static int[] result;
    static int score_inc = 1, score = 0, time_inc = 4, time = 0;
	
	public static void main(String[] args) throws Exception {
		
		ready();
		solve();
	
		bwEnd();
		
	}
	
	static void ready() throws Exception{

        N = Integer.parseInt(br.readLine());
        D = new int[N];
        result = new int[5];
        
        nextLine();
        for(int i=0;i<N;i++) D[i] = nextInt();
		
	}
	
	static void solve() throws Exception{

        for(int op:D){
            if(time > 240) result[init()]++;
            if(op == 1) {
                result[init()]++;
                continue;
            }
            else if(op == 2){
                if(score_inc > 1) score_inc >>= 1;
                else time_inc += 2;
            }
            else if(op == 4) time += 56;
            else if(op == 5) {
                if(time_inc > 1) time_inc--;
            }
            else if(op == 6){
                if(score_inc < 32) score_inc <<= 1;
            }
            score += score_inc;
            time += time_inc;
        }
        
        for(int i=1;i<5;i++) bw.write(result[i] + "\n");
		
	}
	
	static int init(){
	    int res = score;
	    score_inc = 1;
	    score = 0;
	    time_inc = 4;
	    time = 0;
	    if(res < 35) return 0;
	    if(res < 65) return 1;
	    if(res < 95) return 2;
	    if(res < 125) return 3;
	    return 4;
	}
	
}