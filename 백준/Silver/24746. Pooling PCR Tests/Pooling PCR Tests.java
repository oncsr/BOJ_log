import java.io.*;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st = new StringTokenizer("");

    static BigDecimal p, P, N, E, M;
    static int answer = 1;

    public static void main(String[] args) throws Exception {
        p = BigDecimal.valueOf(Double.parseDouble(br.readLine()));
        p = BigDecimal.ONE.subtract(p);

        int gr = 0;
        for(int n=2;n<=16;n++) {
            N = BigDecimal.valueOf(n);
            P = BigDecimal.valueOf(1);
            for(int i=0;i<n;i++) {
                P = P.multiply(p);
            }
            E = P.add(N.multiply(BigDecimal.ONE.subtract(P)));
            E = E.divide(N, 1000, RoundingMode.HALF_UP);
            if(E.compareTo(BigDecimal.ONE) >= 0) {
                gr++;
            }
            if(n == 2) {
                M = E;
                answer = n;
            }
            else {
                if(E.compareTo(M) == -1) {
                    M = E;
                    answer = n;
                }
            }
        }

        if(gr == 15) {
            bw.write("1");
        }
        else {
            bw.write(answer + "\n");
        }

        bw.close();
    }

}