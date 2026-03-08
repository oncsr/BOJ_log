import java.io.*;
import java.util.*;

public class Main {

    static long MOD = (long)1e9 + 7;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for(int Q = Integer.parseInt(br.readLine()); Q-->0; ) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long p = Long.parseLong(st.nextToken());
            long n = Long.parseLong(st.nextToken());

            long ans = (power(p, n) + MOD - 1) * power(p-1, MOD-2) % MOD;

            bw.write(ans + "\n");
        }
        bw.close();

    }

    public static long power(long x, long n) {
        if(n == 0) {
            return 1;
        }
        if(n == 1) {
            return x % MOD;
        }
        long half = power(x, n>>1);
        half = (half * half) % MOD;
        if(n % 2 == 0) {
            return half;
        }
        return half * x % MOD;
    }
}
