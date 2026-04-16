import java.util.*;
import java.io.*;

public class Main{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {

        int N = Integer.parseInt(br.readLine());
        int[][] infos = new int[N][];
        for(int i=0;i<N;i++) {
            st = new StringTokenizer(br.readLine());
            infos[i] = new int[]{Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken())};
        }

        st = new StringTokenizer(br.readLine());
        int L = Integer.parseInt(st.nextToken());
        int P = Integer.parseInt(st.nextToken());

        Arrays.sort(infos, (a,b) -> a[0]-b[0]);
        int idx = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b) -> b-a);
        int ans = 0;

        while(P < L) {
            while(idx < N && infos[idx][0] <= P) pq.offer(infos[idx++][1]);
            if(pq.isEmpty()) break;

            P += pq.poll();
            ans++;

        }

        if(P < L) bw.write("-1");
        else bw.write(ans + "\n");

        bw.close();

    }
}