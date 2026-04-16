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

class Node {
    int cnt;
    Node left, right;
    Node() {
        this.cnt = 0;
    }
}

class Trie {
    Node root;
    Trie() {
        root = new Node();
    }

    void insert(int x) {
        Node now = root;
        for(int i=23;i>=0;i--) {
            int bit = x & (1<<i);
            if(bit == 0) {
                if(now.right == null) now.right = new Node();
                now = now.right;
            }
            else {
                if(now.left == null) now.left = new Node();
                now = now.left;
            }
            now.cnt++;
        }
    }

    void erase(int x) {
        Node now = root;
        eraseDfs(now, x, 23);
    }

    void eraseDfs(Node now, int x, int k) {
        if(k < 0) return;
        if((x & (1<<k)) == 0) {
            eraseDfs(now.right, x, k-1);
            if(--now.right.cnt == 0) now.right = null;
        }
        else {
            eraseDfs(now.left, x, k-1);
            if(--now.left.cnt == 0) now.left = null;
        }
    }

    int min(int x) {
        Node now = root;
        int result = 0;
        for(int i=23;i>=0;i--) {
            int bit = x & (1<<i);
            if(bit == 0) {
                if(now.right == null) {
                    now = now.left;
                    result |= (1<<i);
                }
                else now = now.right;
            }
            else {
                if(now.left == null) now = now.right;
                else {
                    now = now.left;
                    result |= (1<<i);
                }
            }
        }
        return result;
    }

    int max(int x) {
        Node now = root;
        int result = 0;
        for(int i=23;i>=0;i--) {
            int bit = x & (1<<i);
            if(bit == 0) {
                if(now.left == null) now = now.right;
                else{
                    now = now.left;
                    result |= (1<<i);
                }
            }
            else {
                if(now.right == null) {
                    now = now.left;
                    result |= (1<<i);
                }
                else now = now.right;
            }
        }
        return result;
    }
}

public class Main {

    static IOController io;

    //

    static int N, Q;
    static int[] a;
    static TreeMap<Integer, TreeSet<Integer>> info;
    static int bucketSize = 1000, size;
    static Trie[] trie;

    public static void main(String[] args) throws Exception {

        io = new IOController();

        init();
        solve();

        io.close();

    }

    static void init() throws Exception {

        N = io.nextInt();
        a = new int[N];
        for(int i=0;i<N;i++) a[i] = io.nextInt();
        info = new TreeMap<>();
        size = (N-1)/bucketSize + 1;
        trie = new Trie[size];
        for(int i=0;i<size;i++) trie[i] = new Trie();

    }

    static void solve() throws Exception {

        for(int i=0;i<N;i++) {
            int num = i/bucketSize;
            trie[num].insert(a[i]);
            if(!info.containsKey(a[i])) info.put(a[i], new TreeSet<>());
            info.get(a[i]).add(i);
        }

        for(Q=io.nextInt();Q-->0;) {
            int op, l, r, p, x;
            op = io.nextInt();
            if(op == 3) {
                p = io.nextInt()-1;
                x = io.nextInt();
                int num = p/bucketSize;
                trie[num].erase(a[p]);
                info.get(a[p]).remove(p);
                a[p] = x;
                trie[num].insert(a[p]);
                if(!info.containsKey(a[p])) info.put(a[p], new TreeSet<>());
                info.get(a[p]).add(p);
            }
            else {
                l = io.nextInt()-1;
                r = io.nextInt()-1;
                x = io.nextInt();
                int lNum = l/bucketSize, rNum = r/bucketSize;
                if(op == 1) {
                    int res = a[l];
                    for(int i=l;i<Math.min(r+1, (lNum+1)*bucketSize);i++) {
                        if((a[i]^x) < (res^x)) res = a[i];
                    }
                    for(int i=lNum+1;i<rNum;i++) {
                        int tmp = trie[i].min(x);
                        if((tmp^x) < (res^x)) res = tmp;
                    }
                    if(lNum<rNum) {
                        for(int i=rNum*bucketSize;i<=r;i++) {
                            if((a[i]^x) < (res^x)) res = a[i];
                        }
                    }
                    io.write((info.get(res).ceiling(l) + 1) + "\n");
                }
                else {
                    int res = a[l];
                    for(int i=l;i<Math.min(r+1, (lNum+1)*bucketSize);i++) {
                        if((a[i]^x) > (res^x)) res = a[i];
                    }
                    for(int i=lNum+1;i<rNum;i++) {
                        int tmp = trie[i].max(x);
                        if((tmp^x) > (res^x)) res = tmp;
                    }
                    if(lNum<rNum) {
                        for(int i=rNum*bucketSize;i<=r;i++) {
                            if((a[i]^x) > (res^x)) res = a[i];
                        }
                    }
                    io.write((info.get(res).ceiling(l) + 1) + "\n");
                }
            }

        }

    }

}