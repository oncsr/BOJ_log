import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st = new StringTokenizer("");

    public static void main(String[] args) throws Exception {
        int N = Integer.parseInt(br.readLine());
        int MOD = 1000007;

        if(N <= 3) {
            bw.write("1");
        }
        else {
            int a = 0, b = 1;
            for(int i=0;i<N;i++) {
                int prev = b;
                b = (a + b) % MOD;
                a = prev;
            }
            bw.write(a + "\n");
        }

        bw.close();
    }

}