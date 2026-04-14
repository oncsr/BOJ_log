import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static final int MOD = (int)1e9 + 7;

    static int N, L;
    static int[] dp;
    static List<Integer>[] factors;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());

        factors = new List[N+1];
        for(int i=1;i<=N;i++) {
            factors[i] = new ArrayList<>();
            for(int j=1;j<=i;j++) {
                if(i%j == 0) {
                    factors[i].add(j);
                }
            }
        }

        dp = new int[N+1];
        Arrays.fill(dp, 1);
        dp[0] = 0;
        for(int i=2;i<=L;i++) {
            int[] ndp = new int[N+1];
            for(int j=1;j<=N;j++) {
                for(int k : factors[j]) {
                    ndp[j] = (ndp[j] + dp[k]) % MOD;
                }
            }
            dp = ndp;
        }

        int sum = 0;
        for(int i=1;i<=N;i++) {
            sum = (sum + dp[i]) % MOD;
        }

        bw.write(sum + "\n");
        bw.close();
    }
}