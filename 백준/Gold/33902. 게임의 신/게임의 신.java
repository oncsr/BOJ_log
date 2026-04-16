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

    static int x, y;
    static boolean[] d;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    public static void init() throws Exception {

        x = io.nextInt();
        y = io.nextInt();
        d = new boolean[1001];

    }

    static void solve() throws Exception {

        d[y] = true;
        for(int i=y-1;i>=x;i--) {
            for(int j=i+1;j<=y;j++) if(gcd(i,j) == 1) d[i] |= d[j];
            d[i] ^= true;
        }
        
        io.write((d[x] ? "putdata" : "khj20006"));

    }
    
    static int gcd(int x, int y) {
        if(x<y) {
            int t = x;
            x = y;
            y = t;
        }
        return x%y==0 ? y : gcd(y, x%y);
    }

}