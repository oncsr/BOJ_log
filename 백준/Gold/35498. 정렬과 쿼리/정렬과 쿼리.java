import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N, Q;
    static long[] arr, brr;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());

        arr = new long[N+2];
        brr = new long[N+2];
        arr[0] = -(long)1e18;
        arr[N+1] = (long)1e18;
        st = new StringTokenizer(br.readLine());
        int minusCount = 0;
        for(int i=1;i<=N;i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            brr[i] = arr[i] - arr[i-1];
            if(brr[i] < 0) {
                minusCount++;
            }
        }
        brr[N+1] = arr[N+1] - arr[N];

        for(int i=0;i<Q;i++) {
            st = new StringTokenizer(br.readLine());
            int op = Integer.parseInt(st.nextToken());
            if(op == 2) {
                bw.write((minusCount > 0) ? "NO\n" : "YES\n");
            }
            else {
                int l = Integer.parseInt(st.nextToken());
                int r = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                if(brr[l] >= 0 && brr[l] + v < 0) {
                    minusCount++;
                }
                if(brr[l] < 0 && brr[l] + v >= 0) {
                    minusCount--;
                }
                if(brr[r+1] >= 0 && brr[r+1] - v < 0) {
                    minusCount++;
                }
                if(brr[r+1] < 0 && brr[r+1] - v >= 0) {
                    minusCount--;
                }
                brr[l] += v;
                brr[r+1] -= v;
            }
        }
        
        bw.close();
    }
}