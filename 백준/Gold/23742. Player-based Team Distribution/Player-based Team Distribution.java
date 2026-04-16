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

        Arrays.sort(a);

        long ans = 0;
        long sum = 0, cnt = 0;
        for(int i=N-1;i>=0;i--) {
            if((sum + a[i]) * (cnt + 1) >= sum*cnt + a[i]) {
                cnt++;
                sum += a[i];
            }
            else {
                ans += sum*cnt;
                sum = a[i];
                cnt = 1;
            }
        }
        ans += sum*cnt;
        io.write(ans + "\n");

    }

}