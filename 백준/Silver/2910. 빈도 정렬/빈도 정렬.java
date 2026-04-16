import java.math.BigInteger;
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
    static int[] A;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    public static void init() throws Exception {

        N = io.nextInt();
        io.nextInt();
        A = new int[N];
        for(int i=0;i<N;i++) A[i] = io.nextInt();

    }

    static void solve() throws Exception {

        List<Integer>[] B = new List[N+1];
        for(int i=0;i<=N;i++) B[i] = new ArrayList<>();

        Set<Integer> S = new HashSet<>();
        for(int i=0;i<N;i++) if(!S.contains(A[i])) {
            int cnt = 0;
            for(int j=0;j<N;j++) if(A[i] == A[j]) cnt++;
            B[cnt].add(A[i]);
            S.add(A[i]);
        }

        for(int k=N;k>0;k--) for(int i:B[k]) for(int j=0;j<k;j++) io.write(i + " ");

    }

}