import java.util.*;
import java.io.*;

class Main{
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        
        int T = Integer.parseInt(st.nextToken());
        if(T == 1){
            
            long k = Long.parseLong(st.nextToken());
            k--;
            int[] ans = new int[N+1];
            int[] use = new int[N+1];
            long fac = 1;
            for(int i=1;i<N;i++) fac*=i;
            
            for(int j=1;j<N;j++){
                long g = k/fac;
                int p=1, c=0;
                while(use[p] > 0) p++;
                for(;c<g;p++){
                    if(use[p] > 0) continue;
                    c++;
                }
                while(use[p] > 0) p++;
                k -= g*fac;
                ans[j] = p;
                use[p]++;
                fac/=(N-j);
            }
            for(int i=1;i<=N;i++){
                if(use[i] == 0){
                    ans[N] = i;
                    break;
                }
            }
            for(int i=1;i<=N;i++) bw.write(ans[i] + " ");
            
        }
        else{
            
            long fac = 1;
            int[] use = new int[N+1];
            long ans = 0;
            for(int i=1;i<N;i++) fac*=i;
            for(int i=1;i<=N;i++){
                int a = Integer.parseInt(st.nextToken());
                int c = 0;
                for(int j=1;j<a;j++){
                    if(use[j] > 0) continue;
                    c++;
                }
                ans += fac*c;
                use[a]++;
                if(i < N) fac /= (N-i);
            }
            bw.write((ans+1)+"\n");
            
        }
        
        
        bw.flush();
        bw.close();
    }
    
}