import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N, M, C, D;
    static int[] arr, dp, pos;
    static Deque<int[]>[] deque;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());

        arr = new int[N+1];
        st = new StringTokenizer(br.readLine());
        for(int i=1;i<=N;i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        dp = new int[M+1];
        for(int i=1;i<=N;i++) {
            int[] ndp = new int[M+1];
            pos = new int[C];
            pos[0] = 1;
            deque = new Deque[C];
            for(int j=0;j<C;j++) {
                deque[j] = new ArrayDeque<>();
            }
            for(int t=1;t<=M;t++) {
                int p = t/C, q = t%C;
                while(pos[q] <= p + D/C) {
                    if(pos[q] * C + q > M) {
                        break;
                    }

                    int val = dp[pos[q]*C + q];
                    while(!deque[q].isEmpty() && deque[q].peekLast()[0] <= val) {
                        deque[q].pollLast();
                    }
                    deque[q].addLast(new int[]{val, pos[q]++});
                }
                while(!deque[q].isEmpty() && p - deque[q].peekFirst()[1] > D/C) {
                    deque[q].pollFirst();
                }
                ndp[t] = deque[q].peekFirst()[0] + M - Math.abs(t-arr[i]);
            }
            dp = ndp;
        }
        int answer = 0;
        for(int i=1;i<=M;i++) {
            answer = Math.max(answer, dp[i]);
        }
        bw.write(answer + "\n");

        bw.close();
    }
}
