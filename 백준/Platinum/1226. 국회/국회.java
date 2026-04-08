import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N, K = 0;
    static int[][] arr;
    static boolean[] dp;
    static int[] one;

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());

        arr = new int[N][];
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<N;i++) {
            int a = Integer.parseInt(st.nextToken());
            arr[i] = new int[]{a, i+1};
            K += a;
        }

        Arrays.sort(arr, (a,b) -> b[0]-a[0]);
        dp = new boolean[K+1];
        one = new int[K+1];
        dp[0] = true;

        int answer = 0;
        List<Integer> list = new ArrayList<>();
        for(int i=0;i<N;i++) {
            int val = arr[i][0], idx = arr[i][1];

            for(int j=K/2;j>Math.max(-1, K/2-val);j--) if(dp[j]) {
                if(j+val > answer) {
                    answer = j+val;
                    list = new ArrayList<>();
                    list.add(i);
                    while(j > 0) {
                        list.add(one[j]);
                        j -= arr[one[j]][0];
                    }
                    break;
                }
            }

            for(int j=K;j>=val;j--) {
                if(dp[j-val] && !dp[j]) {
                    dp[j] = true;
                    one[j] = i;
                }
            }
        }

        bw.write(list.size() + "\n");
        for(int i : list) {
            bw.write(arr[i][1] + " ");
        }
        
        bw.close();
    }
}