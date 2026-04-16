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
    static int ans = 0;
    static int[] arr;
    static int except = (1<<('a'-'a')) | (1<<('n'-'a')) | (1<<('t'-'a')) | (1<<('i'-'a')) | (1<<('c'-'a'));

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    static void init() throws Exception {

        N = io.nextInt();
        K = io.nextInt();
        arr = new int[N];
        for(int i=0;i<N;i++) for(char c:io.nextLine().toCharArray()) arr[i] |= (1<<(c-'a'));

    }

    static void solve() throws Exception {

        bck('a',0,0);
        io.write(ans + "\n");

    }

    static void bck(char cur, int cnt, int state) {
        if(cur > 'z') {
            if(cnt == K) {
                int res = 0;
                for(int i=0;i<N;i++) res += (arr[i] & state) == arr[i] ? 1 : 0;
                ans = Math.max(ans, res);
            }
            return;
        }
        if((except & (1<<(cur-'a'))) != 0) bck((char)(cur+1), cnt+1, state|(1<<(cur-'a')));
        else {
            bck((char)(cur+1), cnt, state);
            bck((char)(cur+1), cnt+1, state|(1<<(cur-'a')));
        }
    }

}