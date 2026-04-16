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

    static int N, M, K;
    static int[][] A;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();
    }

    public static void init() throws Exception {

        N = io.nextInt();
        M = io.nextInt();
        A = new int[N][M];
        for(int i=0;i<N;i++) {
            char[] line = io.nextToken().toCharArray();
            for(int j=0;j<M;j++) A[i][j] = line[j]%2;
        }
        K = io.nextInt();

    }

    static void solve() throws Exception {

        int ans = 0;
        for(int i=0;i<N;i++) {
            int cnt = 0;
            for(int j=0;j<M;j++) {
                if(A[i][j] == 0) cnt++;
            }
            if(K >= cnt && (K-cnt)%2 == 0) {
                int[][] B = new int[N][M];
                int res = 0;
                for(int x=0;x<N;x++) {
                    int temp = 0;
                    for(int y=0;y<M;y++) {
                        temp += A[x][y] ^ A[i][y] ^ 1;
                    }
                    if(temp == M) res++;
                }
                ans = Math.max(ans, res);
            }
        }
        io.write(ans + "\n");

    }

}