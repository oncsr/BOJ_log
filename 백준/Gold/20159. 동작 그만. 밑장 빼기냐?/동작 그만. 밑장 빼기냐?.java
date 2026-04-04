import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N;
    static int[] arr, left, right;

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());

        arr = new int[N+2];
        st = new StringTokenizer(br.readLine());
        for(int i=1;i<=N;i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        left = new int[N+2];
        for(int i=1;i<=N;i++) {
            left[i] = left[i-1];
            if(i%2 == 1) left[i] += arr[i];
        }

        right = new int[N+2];
        for(int i=N;i>=1;i--) {
            right[i] = right[i+1];
            if(i%2 == 0) right[i] += arr[i];
        }

        int answer = 0;
        for(int i=1;i<=N;i++) {
            int val = left[i-1] + right[i];
            if(i%2 == 0) val -= arr[N];
            answer = Math.max(answer, val);
        }

        bw.write(answer + "\n");
        bw.close();
    }
}
