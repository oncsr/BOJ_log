import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        long N = Long.parseLong(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        PriorityQueue<Long> pq = new PriorityQueue<>((a,b) -> Long.compare(b,a));

        long ans = 0;
        for(int i=0;i<N;i++) {
            long a = Long.parseLong(st.nextToken()) - i;
            pq.add(a);
            if(pq.peek() > a) {
                ans += pq.poll() - a;
                pq.add(a);
            }
        }
        
        bw.write(ans + "\n");
        bw.close();
    }
}