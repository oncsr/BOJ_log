import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st = new StringTokenizer("");

    static int N;
    static long[] arr;

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());
        arr = new long[N];
        for(int i=0;i<N;i++) {
            String[] temp = br.readLine().split("\\.");
            for(int j=0;j<4;j++) {
                arr[i] |= (Long.parseLong(temp[j]) << 8*(3-j));
            }
        }

        int cnt = 0;
        for(int i=31;i>=0;i--) {
            long base = arr[0] & (1L << i);
            boolean same = true;
            for(int j=1;j<N;j++) {
                if(base != (arr[j] & (1L << i))) {
                    same = false;
                    break;
                }
            }
            if(!same) {
                break;
            }
            cnt++;
        }
        if(cnt == 0) cnt = 32;

        bw.write(cnt + "\n");

        bw.close();
    }

}