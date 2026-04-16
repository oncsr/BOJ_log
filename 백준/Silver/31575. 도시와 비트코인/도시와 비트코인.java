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

    static int N, M;
    static int[][] A;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();
    }

    public static void init() throws Exception {

        M = io.nextInt();
        N = io.nextInt();
        A = new int[N+1][M+1];
        for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) A[i][j] = io.nextInt();

    }

    static void solve() throws Exception {

        A[1][0] = 1;
        for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) if(A[i][j] == 1) {
            if(A[i-1][j] + A[i][j-1] == 0) A[i][j] = 0;
        }
        io.write(A[N][M] == 1 ? "Yes" : "No");

    }

}