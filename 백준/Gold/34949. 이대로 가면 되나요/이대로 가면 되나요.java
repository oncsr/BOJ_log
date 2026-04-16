import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br;
    static BufferedWriter bw;
    static StringTokenizer st;

    static int N;
    static List<Integer>[] graph;
    static int[] f;

    public static void main(String[] args) throws Exception {
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        input();
        solve();

        bw.close();
    }

    public static void input() throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        graph = new List[N+1];
        for(int i=1;i<=N;i++) graph[i] = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for(int i=1;i<=N;i++) {
            int a = Integer.parseInt(st.nextToken());
            graph[a].add(i);
        }

        br.close();
    }

    public static void solve() throws Exception {
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        f = new int[N+1];
        Arrays.fill(f, -1);
        Queue<Integer> queue = new ArrayDeque<>();
        queue.add(N);
        f[N] = 0;
        while(!queue.isEmpty()) {
            int now = queue.poll();
            for(int nxt : graph[now]) if(f[nxt] == -1) {
                queue.add(nxt);
                f[nxt] = f[now]+1;
            }
        }
        for(int i=1;i<=N;i++) bw.write(f[i] + "\n");

        bw.close();
    }

}