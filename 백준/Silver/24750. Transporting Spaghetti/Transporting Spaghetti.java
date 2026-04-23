import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st = new StringTokenizer("");

    static long A, B, C, D;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());

        for(int t=0;t<=1000000;t++) {
            if(A*t - D >= C && (A*t - D) % B == 0) {
                long b = (A*t - D) / B;
                bw.write("We need " + t + " truck");
                if(t != 1) {
                    bw.write("s");
                }
                bw.write(" and " + b + " boat");
                if(b != 1) {
                    bw.write("s");
                }
                bw.write(".");
                bw.close();
                return;
            }
        }

        bw.write("No solution.");
        bw.close();
    }

}