import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static String line;
    static long P, B, N, D;

    public static long power(long a, long b, long mod) {
        long ret = 1;
        while(b > 0) {
            if((b&1) == 1) {
                ret = ret * a % mod;
            }
            b >>= 1;
            a = a * a % mod;
        }
        return ret;
    }

    public static void main(String[] args) throws Exception {
        while((line = br.readLine()) != null) {
            st = new StringTokenizer(line);
            long P = Integer.parseInt(st.nextToken());
            long B = Integer.parseInt(st.nextToken());
            long N = Integer.parseInt(st.nextToken());
            D = (long)Math.sqrt(P);

            List<long[]> left = new ArrayList<>();
            long BG = power(B, D, P);
            long leftVal = 1;
            for(int i=0;i<P/D;i++) {
                left.add(new long[]{leftVal, i});
                leftVal = leftVal * BG % P;
            }

            List<long[]> right = new ArrayList<>();
            for(int i=0;i<D;i++) {
                right.add(new long[]{N * power(B, P-i-1, P) % P, i});
            }

            Collections.sort(left, (a,b) -> Long.compare(a[0], b[0]));
            Collections.sort(right, (a,b) -> Long.compare(a[0], b[0]));
            int l = 0, r = 0;
            long answer = P*P;
            while(l<left.size() && r<right.size()) {
                long[] le = left.get(l);
                long[] ri = right.get(r);
                if(le[0] == ri[0]) {
                    answer = Math.min(answer, D*le[1] + ri[1]);
                }
                if(le[0] < ri[0]) {
                    l++;
                }
                else {
                    r++;
                }
            }

            if(answer == P*P) {
                bw.write("no solution\n");
            }
            else {
                bw.write(answer + "\n");
            }
        }

        bw.close();
    }
}