import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st = new StringTokenizer("");

    public static void main(String[] args) throws Exception {
        int T = Integer.parseInt(br.readLine());
        while(T-- > 0) {
            int N = Integer.parseInt(br.readLine());

            long A = 0, B = 0, C = 0, P = 0;
            boolean result = true;
            for(int i=0;i<N;i++) {
                st = new StringTokenizer(br.readLine());
                long a = Long.parseLong(st.nextToken());
                long b = Long.parseLong(st.nextToken());
                long c = Long.parseLong(st.nextToken());
                long p = Long.parseLong(st.nextToken());

                if(a > A) {
                    P += a-A;
                    A = a;
                }
                if(b > B) {
                    P += b-B;
                    B = b;
                }
                if(c > C) {
                    P += c-C;
                    C = c;
                }
                P++;
                if(P > p) {
                    result = false;
                }
            }
            bw.write(result ? "YES\n" : "NO\n");
        }

        bw.close();
    }

}