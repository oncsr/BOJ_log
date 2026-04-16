import java.util.*;
import java.io.*;

class IOController {
    BufferedReader br;
    BufferedWriter bw;
    StringTokenizer st;

    public IOController() {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        st = new StringTokenizer("");
    }

    String nextLine() throws Exception {
        String line = br.readLine();
        st = new StringTokenizer(line);
        return line;
    }

    String nextToken() throws Exception {
        while (!st.hasMoreTokens()) nextLine();
        return st.nextToken();
    }

    int nextInt() throws Exception {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws Exception {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws Exception {
        return Double.parseDouble(nextToken());
    }

    void close() throws Exception {
        bw.flush();
        bw.close();
    }

    void write(String content) throws Exception {
        bw.write(content);
    }

}

public class Main {

    static IOController io;

    //

    static int A, B;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    public static void init() throws Exception {

        A = io.nextInt();
        B = io.nextInt();

    }

    static void solve() throws Exception {

        int ans = 0;
        for(int i=A;i<=B;i++) {
            int t = i, cnt = 0;
            for(int j=2;j*j<=t;j++) {
                while(t%j == 0) {
                    t /= j;
                    cnt++;
                }
            }
            if(t != 1) cnt++;

            boolean sosu = cnt != 1;
            for(int j=2;j<cnt;j++) sosu &= cnt%j!=0;
            if(sosu) ans++;
        }
        io.write(ans + "\n");

    }

}