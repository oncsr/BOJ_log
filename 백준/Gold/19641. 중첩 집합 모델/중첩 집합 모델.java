import java.util.*;
import java.io.*;

class Main {
    
    static int o = 0;
    static int[] left = new int[100001];
    static int[] right = new int[100001];
    static int[][] V = new int[100001][];
    
    static void dfs(int n, int p){
        left[n] = ++o;
        for(int i:V[n]){
            if(i == p) continue;
            dfs(i,n);
        }
        right[n] = ++o;
    }
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int N = Integer.parseInt(br.readLine());
        for(int i=0;i<N;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            
            int n = Integer.parseInt(st.nextToken());
            V[n] = new int[st.countTokens()-1];
            for(int j=0;j<V[n].length;j++){
                V[n][j] = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(V[n]);
        }
        dfs(Integer.parseInt(br.readLine()), 0);
        
        for(int i=1;i<=N;i++) bw.write(i + " " + left[i] + " " + right[i] + "\n");
        
        bw.flush();
        bw.close();
    }
}