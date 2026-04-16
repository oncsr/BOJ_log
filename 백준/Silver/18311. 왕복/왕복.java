import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] arr;
    static long K;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Long.parseLong(st.nextToken());

        st = new StringTokenizer(br.readLine());
        arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        long dist = 0;
        for (int i = 0; i < N; i++) {
            if (dist <= K && K < dist + arr[i]) {
                System.out.println((i + 1));
                return;
            }
            dist += arr[i];
        }
        for (int i = N - 1; i >= 0; i--) {
            if (dist <= K && K < dist + arr[i]) {
                System.out.println((i + 1));
                return;
            }
            dist += arr[i];
        }
    }
}