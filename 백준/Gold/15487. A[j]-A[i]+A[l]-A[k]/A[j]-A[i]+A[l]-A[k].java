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

    static final int INF = -(int)1e9 - 7;

    static int N;
    static int[] a;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    public static void init() throws Exception {

        N = io.nextInt();
        a = new int[N];
        for(int i=0;i<N;i++) a[i] = io.nextInt();

    }

    static void solve() throws Exception {

        int[] left = new int[N];
        left[0] = INF;
        int min = a[0];
        for(int i=1;i<N;i++) {
            left[i] = Math.max(left[i-1], a[i] - min);
            min = Math.min(min, a[i]);
        }

        int[] right = new int[N];
        right[N-1] = INF;
        int max = a[N-1];
        for(int i=N-2;i>=0;i--) {
            right[i] = Math.max(right[i+1], max - a[i]);
            max = Math.max(max, a[i]);
        }

        int ans = INF;
        for(int i=1;i<N-2;i++) ans = Math.max(ans, left[i] + right[i+1]);
        io.write(ans + "\n");

    }

}