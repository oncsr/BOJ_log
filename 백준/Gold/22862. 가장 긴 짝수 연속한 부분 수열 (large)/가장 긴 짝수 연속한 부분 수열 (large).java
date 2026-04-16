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

    static int N, K;
    static int[] a;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    public static void init() throws Exception {

        N = io.nextInt();
        K = io.nextInt();
        a = new int[N+1];
        for(int i=1;i<=N;i++) a[i] = io.nextInt()%2;

    }

    static void solve() throws Exception {

        int even = 0, odd = 0, ans = 0;
        for(int s=1,e=1;e<=N;e++) {
            if(a[e] == 1) odd++;
            else even++;
            while(odd > K) {
                if(a[s] == 1) odd--;
                else even--;
                s++;
            }
            if(even > 0) ans = Math.max(ans, e-s+1-odd);
        }
        io.write(ans + "\n");

    }

}