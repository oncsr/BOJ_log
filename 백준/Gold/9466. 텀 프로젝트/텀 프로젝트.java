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
    static int[] g;
    static int[] v;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        int T = io.nextInt();
        while(T-->0) {
            init();
            solve();
        }

        io.close();

    }

    public static void init() throws Exception {

        N = io.nextInt();
        g = new int[N+1];
        for(int i=1;i<=N;i++) g[i] = io.nextInt();
        v = new int[N+1];

    }

    static void solve() throws Exception {

        int ans = N, num = 1;
        for(int i=1;i<=N;i++) if(v[i] == 0) {
            Stack<Integer> s = new Stack<>();
            int x = i;
            while(v[x] == 0) {
                s.add(x);
                v[x] = num;
                x = g[x];
            }
            if(v[x] != num) {
                num++;
                continue;
            }
                
            while(!s.isEmpty()) {
                int top = s.pop();
                ans--;
                if(top == x) break;
            }
            num++;
        }
        io.write(ans + "\n");

    }

}