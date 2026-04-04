import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N, Q;
    static int[] c, o, w;

    public static void main(String[] args) throws Exception {
        char[] arr = ("_" + br.readLine()).toCharArray();

        N = arr.length - 1;
        c = new int[N+1];
        o = new int[N+1];
        w = new int[N+1];
        for(int i=1;i<=N;i++) {
            if(arr[i] == 'C') c[i]++;
            if(arr[i] == 'O') o[i]++;
            if(arr[i] == 'W') w[i]++;
            c[i] += c[i-1];
            o[i] += o[i-1];
            w[i] += w[i-1];
        }

        Q = Integer.parseInt(br.readLine());
        for(int i=0;i<Q;i++) {
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            int countC = c[r] - c[l-1];
            int countO = o[r] - o[l-1];
            int countW = w[r] - w[l-1];

            if((countO + countW) % 2 == 0 && (countO + countC) % 2 == 1) {
                bw.write("Y");
            }
            else {
                bw.write("N");
            }
        }
        
        bw.close();
    }
}
