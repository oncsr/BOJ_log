import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static final int INF = -(int)1e9 + 7;
    static int N, K;
    static int[][] dp;
    static int[] arr;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        dp = new int[8][K+1];
        for(int i=0;i<8;i++) {
            Arrays.fill(dp[i], INF);
        }

        arr = new int[3];
        st = new StringTokenizer(br.readLine());
        for(int j=0;j<3;j++) {
            arr[j] = Integer.parseInt(st.nextToken());
        }
        dp[0][0] = 0;
        dp[3][1] = arr[0] + arr[1];
        dp[6][1] = arr[1] + arr[2];

        for(int i=1;i<N;i++) {
            st = new StringTokenizer(br.readLine());
            int[] narr = new int[3];
            int[][] ndp = new int[8][K+1];
            for(int j=0;j<8;j++) {
                Arrays.fill(ndp[j], INF);
            }

            for(int j=0;j<3;j++) {
                narr[j] = Integer.parseInt(st.nextToken());
            }

            for(int k=0;k<=K;k++) {
                for(int a=0;a<2;a++) for(int b=0;b<2;b++) for(int c=0;c<2;c++) {
                    int state = (a << 0) | (b << 1) | (c << 2);

                    if(a+b+c == 0) {
                        for(int j=0;j<8;j++) {
                            ndp[state][k] = Math.max(ndp[state][k], dp[j][k]);
                        }
                    }
                    else if(a+b+c == 1) {
                        if(k > 0) {
                            int idx = (a == 1 ? 0 : (b == 1 ? 1 : 2));
                            int o1 = (a == 1 ? 1 : 0);
                            int o2 = (c == 1 ? 1 : 2);
                            for(int x=0;x<2;x++) for(int y=0;y<2;y++) {
                                ndp[state][k] = Math.max(ndp[state][k], dp[(x << o1) | (y << o2)][k-1]);
                            }
                            ndp[state][k] += arr[idx] + narr[idx];
                        }
                    }
                    else if(a+b+c == 2) {
                        if(b == 0) {
                            if(k > 1) {
                                ndp[state][k] = Math.max(dp[0][k-2], dp[2][k-2]) + arr[0] + arr[2] + narr[0] + narr[2];
                            }
                        }
                        else {
                            if(k > 0) {
                                int idx1 = (c == 0 ? 0 : 1);
                                int idx2 = (c == 0 ? 1 : 2);
                                for(int j=0;j<8;j++) {
                                    ndp[state][k] = Math.max(ndp[state][k], dp[j][k-1] + narr[idx1] + narr[idx2]);
                                }
                            }
                        }
                    }
                    else {
                        if(k > 1) {
                            for(int x=0;x<2;x++) for(int y=0;y<2;y++) {
                                ndp[state][k] = Math.max(ndp[state][k], dp[(x << 1) | (y << 2)][k-2] + arr[0] + narr[0] + narr[1] + narr[2]);
                                ndp[state][k] = Math.max(ndp[state][k], dp[(x << 0) | (y << 1)][k-2] + arr[2] + narr[0] + narr[1] + narr[2]);
                            }
                        }
                    }

                    ndp[state][k] = Math.max(ndp[state][k], dp[state][k]);
                }
            }
            dp = ndp;
            arr = narr;
        }
        int answer = INF;
        for(int i=0;i<8;i++) {
            answer = Math.max(answer, dp[i][K]);
        }

        bw.write(answer + "\n");
        bw.close();
    }
}