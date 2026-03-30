import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    static final int INF = 123456789;

    static int N;
    static int[] dist;

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());

        dist = new int[N];
        Arrays.fill(dist, INF);
        dist[0] = 0;

        st = new StringTokenizer(br.readLine());
        for(int i=1;i<N;i++) {
            int a = Integer.parseInt(st.nextToken());
            if(a == 0) continue;
            for(int j=1;j<N;j++) {
                dist[j*(N-i)%N] = Math.min(dist[j*(N-i)%N], a*j);
            }
        }
        for(int i=0;i<N;i++) for(int x=1;x<N;x++) {
            dist[(i+x)%N] = Math.min(dist[(i+x)%N], dist[i] + dist[x]);
        }

        int Q = Integer.parseInt(br.readLine());
        for(int i=0;i<Q;i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int val = dist[(b+N-a)%N];
            bw.write((val == INF ? -1 : val) + "\n");
        }
        
        bw.close();
    }
}
