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
    static List<Integer>[] graph;
    static boolean[] vis;
    static int tail = 0, down = 0, mid = 0, left = 0, right = 0, up = 0;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    static void init() throws Exception {

        N = io.nextInt();
        graph = new List[N+1];
        for(int i=1;i<=N;i++) graph[i] = new ArrayList<>();
        for(int i=0;i<N+3;i++) {
            int a = io.nextInt();
            int b = io.nextInt();
            graph[a].add(b);
            graph[b].add(a);
        }
        vis = new boolean[N+1];

    }

    static void solve() throws Exception {

        int tail = 0;
        for(int i=1;i<=N;i++) if(graph[i].size() == 1) {
            tail = i;
            break;
        }

        vis[tail] = true;
        findDown(tail);

        for(int i:graph[down]) if(!vis[i]) {
            vis[i] = true;
            findMid(i);
        }

        for(int i=1;i<=N;i++) if(!vis[i] && graph[i].size() > 2) {
            up = i;
            break;
        }

        io.write(up + " " + left + " " + mid + " " + right + " " + down + " " + tail);

    }

    static void findDown(int n) {
        if(graph[n].size() > 2) {
            down = n;
            return;
        }
        for(int i:graph[n]) if(!vis[i]) {
            vis[i] = true;
            findDown(i);
        }
    }

    static void findMid(int n) {
        if(graph[n].size() == 4) {
            mid = n;
            return;
        }
        if(graph[n].size() == 3) {
            if(right == 0) right = n;
            else left = n;
            if(left > right) {
                int temp = left;
                left = right;
                right = temp;
            }
            return;
        }
        for(int i:graph[n]) if(!vis[i]) {
            vis[i] = true;
            findMid(i);
        }
    }

}