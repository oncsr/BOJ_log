import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long[] cnt = new long[100001];
        int[] root = new int[100001];
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        
        for(int i=1;i<=N;i++){
            root[i] = i;
            cnt[i] = 1;
        }
        
        int[][] E = new int[M][3];
        for(int i=0,a,b,c;i<M;i++){
            st = new StringTokenizer(br.readLine());
            E[i][1] = Integer.parseInt(st.nextToken());
            E[i][2] = Integer.parseInt(st.nextToken());
            E[i][0] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(E, new Comparator<int[]>() {
            public int compare(int[] o1, int[] o2) {
                return o2[0] - o1[0];
            }
        });
        
        long ans = 0L, mod = (long)1e9, k = 0L;
        for(int i=0;i<M;i++){
            long c = (long)E[i][0];
            int a = E[i][1], b = E[i][2];
            
            int x = a, y = b;
            ArrayList<Integer> temp = new ArrayList<>();
            while(x != root[x]) {
                temp.add(x);
                x = root[x];
            }
            for(int j:temp) root[j] = x;
            
            temp = new ArrayList<>();
            while(y != root[y]){
                temp.add(y);
                y = root[y];
            }
            for(int j:temp) root[j] = y;
            
            if(x != y){
                k += (long)cnt[x] * cnt[y];
                cnt[y] += cnt[x];
                root[x] = y;
            }
            ans = (ans + c*k) % mod;
        }
        System.out.print(ans);
    }
}