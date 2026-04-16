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
        for(int i=1;i<=N;i++) a[i] = io.nextInt();

    }

    static void solve() throws Exception {

        TreeMap<Integer, Integer> map = new TreeMap<>();
        for(int i=1;i<=N;i++) {
            a[i] += a[i-1];
            map.put(a[i], map.getOrDefault(a[i], 0) + 1);
        }

        long ans = 0;
        for(int i=1;i<=N;i++) {
            ans += map.getOrDefault(a[i-1] + K, 0);
            map.put(a[i], map.get(a[i]) - 1);
        }
        io.write(ans + "\n");

    }

}