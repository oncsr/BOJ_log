import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static long N, K;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        long[] order = new long[(int)K+2];
        order[0] = 1;
        order[(int)K+1] = N;

        int l = 1, r = (int)K;
        long s = 2, e = K+1;
        boolean turn = false;
        for(int i=0;i<K/2;i++) {
            if(!turn) {
                order[l++] = e--;
                order[r--] = s++;
            }
            else {
                order[l++] = s++;
                order[r--] = e--;
            }
            turn ^= true;
        }
        if(K%2 == 1) {
            order[l] = s;
        }

        long answer = 0;
        for(int i=0;i<=K;i++) {
            answer += order[i] * order[i+1];
        }
        bw.write(answer + "\n");
        
        bw.close();
    }
}