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

    static int N, L;
    static int ans = 0;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        int T = io.nextInt();
        for (int i = 0; i < T; i++) {
            init();
            solve();

        }

        io.close();

    }

    public static void init() throws Exception {

        N = io.nextInt();
        L = io.nextInt();
        ans = 0;

    }

    static void solve() throws Exception {

        if(L == 1) {
            io.write((N == 1 ? 1 : 0) + "\n");
            return;
        }
        bck(1,N);
        io.write(ans + "\n");

    }

    static void bck(int idx, int val) {
        if(idx == L-1) {
            if(val > 1) ans++;
            return;
        }
        for(int j=1;j*j<val;j++) bck(idx+1, j);
    }

}