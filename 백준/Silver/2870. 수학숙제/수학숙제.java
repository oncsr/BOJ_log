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
    static List<BigInteger> A;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    public static void init() throws Exception {

        N = io.nextInt();
        A = new ArrayList<>();

    }

    static void solve() throws Exception {

        while(N-- > 0) {
            String line = io.nextToken();
            String num = "";
            for(char i : line.toCharArray()) {
                if('0' <= i && i <= '9') num += i;
                else {
                    if(!num.isEmpty()) {
                        A.add(new BigInteger(num));
                        num = "";
                    }
                }
            }
            if(!num.isEmpty()) {
                A.add(new BigInteger(num));
                num = "";
            }
        }
        
        Collections.sort(A);
        for(BigInteger i:A) io.write(i + "\n");

    }

}