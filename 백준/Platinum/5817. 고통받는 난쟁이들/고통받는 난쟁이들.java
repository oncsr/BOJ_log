import java.util.*;
import java.io.*;

class Main{
    static int N, M;
    static int[] L = new int[524289];
    static int[] R = new int[524289];
    static int[] P = new int[200001];
    static int[] Q = new int[200001];
    
    static void init(int s, int e, int n){
        if(s == e){
            L[n] = P[s];
            R[n] = P[s];
            return;
        }
        int m=(s+e)>>1;
        init(s,m,n*2);
        init(m+1,e,n*2+1);
        L[n] = Math.min(L[n*2], L[n*2+1]);
        R[n] = Math.max(R[n*2], R[n*2+1]);
    }
    
    static void upt(int s, int e, int i, int v, int n){
        if(s == e){
            L[n] = v;
            R[n] = v;
            return;
        }
        int m=(s+e)>>1;
        if(i <= m) upt(s,m,i,v,n*2);
        else upt(m+1,e,i,v,n*2+1);
        L[n] = Math.min(L[n*2], L[n*2+1]);
        R[n] = Math.max(R[n*2], R[n*2+1]);
    }
    
    static int find(int s, int e, int l, int r, int n, int t){
        if(l>r || l>e || r<s) return t==0 ? (int)1e9 : 0;
        if(l<=s && e<=r) return t==0 ? L[n] : R[n];
        int m=(s+e)>>1;
        if(t==0) return Math.min(find(s,m,l,r,n*2,t), find(m+1,e,l,r,n*2+1,t));
        return Math.max(find(s,m,l,r,n*2,t),find(m+1,e,l,r,n*2+1,t));
    }
    
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for(int i=1;i<=N;i++){
            Q[i] = Integer.parseInt(st.nextToken());
            P[Q[i]] = i;
        }
        
        init(1,N,1);
        while(M-->0){
            st = new StringTokenizer(br.readLine());
            int o = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            
            if(o == 1){
                int x = Q[a], y = Q[b];
                upt(1,N,x,b,1);
                upt(1,N,y,a,1);
                int temp = x;
                Q[a] = y;
                Q[b] = temp;
            }
            else{
                if(find(1,N,a,b,1,1) - find(1,N,a,b,1,0) == b-a) bw.write("YES\n");
                else bw.write("NO\n");
            }
        }
        
        bw.flush();
        bw.close();
    }
}