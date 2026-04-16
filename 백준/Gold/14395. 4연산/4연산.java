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

    static long s, t;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();
    }

    public static void init() throws Exception {

        s = io.nextLong();
        t = io.nextLong();

    }

    static void solve() throws Exception {

        if(s == t) {
            io.write("0");
            return;
        }
        class Node {
            long val;
            String res;
            Node(long val, String res) {
                this.val = val;
                this.res = res;
            }
        }
        Set<Long> visited = new TreeSet<>();
        Queue<Node> q = new LinkedList<>();

        visited.add(s);
        q.add(new Node(s, ""));
        if(!visited.contains(s*s)) {
            visited.add(s*s);
            q.add(new Node(s*s, "*"));
        }
        if(!visited.contains(2*s)) {
            visited.add(2*s);
            q.add(new Node(2*s, "+"));
        }
        if(!visited.contains(0L)) {
            visited.add(0L);
            q.add(new Node(0L, "-"));
        }
        if(!visited.contains(1L)) {
            visited.add(1L);
            q.add(new Node(1L, "/"));
        }

        while (!q.isEmpty()) {
            Node curr = q.poll();
            long v = curr.val;
            String r = curr.res;
            if(v == t) {
                io.write(r);
                return;
            }
            if(v > t) continue;
            if(!visited.contains(v*v)) {
                visited.add(v*v);
                q.add(new Node(v*v, r+"*"));
            }
            if(!visited.contains(2*v)) {
                visited.add(2*v);
                q.add(new Node(2*v, r+"+"));
            }
        }
        io.write("-1");

    }

}