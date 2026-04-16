import java.util.*;
import java.io.*;

class Main{
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());
        
        ArrayList<Integer>[] V = new ArrayList[N+1];
        for(int i=0;i<=N;i++) V[i] = new ArrayList<>();
        int[] vis = new int[N+1];
        
        for(int i=0;i<M;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            V[a].add(b);
            V[b].add(a);
        }
        
        Queue<Integer> qx = new LinkedList<>();
        Queue<Integer> qt = new LinkedList<>();
        
        qx.add(R);
        qt.add(0);
        vis[R]++;
        
        int[] ans = new int[N+1];
        for(int i=1;i<=N;i++) ans[i] = -1;
        while(!qx.isEmpty()){
            int x = qx.remove();
            int t = qt.remove();
            ans[x] = t;
            for(int i:V[x]){
                if(vis[i] > 0) continue;
                qx.add(i);
                qt.add(t+1);
                vis[i]++;
            }
        }
        for(int i=1;i<=N;i++) bw.write(ans[i] + "\n");
        
        bw.flush();
        bw.close();
    }
    
}