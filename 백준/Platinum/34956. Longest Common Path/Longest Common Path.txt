import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static int N;
    static Map<String, Integer> edgeMap;
    static List<Integer>[] graph;
    static int maxDist = -1;
    static int curDist = 0;
    static int[] answer = {0,0};
    static int[] diameter = {0,0};
    static boolean[] visited;

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());

        edgeMap = new TreeMap<>();
        for(int i=0;i<2*N-2;i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if(a > b) {
                int temp = a;
                a = b;
                b = temp;
            }
            edgeMap.put(a + " " + b, edgeMap.getOrDefault(a + " " + b, 0) + 1);
        }

        graph = new List[N+1];
        for(int i=1;i<=N;i++) {
            graph[i] = new ArrayList<>();
        }

        for(String key : edgeMap.keySet()) {
            if(edgeMap.get(key) != 2) continue;
            String[] splt = key.split(" ");
            int a = Integer.parseInt(splt[0]);
            int b = Integer.parseInt(splt[1]);
            graph[a].add(b);
            graph[b].add(a);
        }

        visited = new boolean[N+1];
        for(int i=1;i<=N;i++) if(!visited[i] && !graph[i].isEmpty()) {
            curDist = 0;
            dfs(i, 0, 0, 0);
            curDist = 0;
            dfs(diameter[0], 0, 0, 1);
            if(curDist > maxDist) {
                maxDist = curDist;
                answer[0] = diameter[0];
                answer[1] = diameter[1];
            }
        }

        if(maxDist == -1) {
            bw.write("-1");
        }
        else {
            bw.write(answer[0] + " " + answer[1]);
        }
        
        bw.close();
    }

    public static void dfs(int cur, int par, int dist, int dfsNum) {
        if(dfsNum == 1) {
            visited[cur] = true;
        }
        if(dist > curDist) {
            curDist = dist;
            diameter[dfsNum] = cur;
        }
        for(int nxt : graph[cur]) if(nxt != par) {
            dfs(nxt, cur, dist+1, dfsNum);
        }
    }
}