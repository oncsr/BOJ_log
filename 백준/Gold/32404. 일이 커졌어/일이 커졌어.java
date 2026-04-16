import java.util.*;
import java.io.*;

class Main{
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        
        int N = Integer.parseInt(br.readLine());
        int[] ans = new int[N];
        int s = 1, e = N;
        for(int i=N-1;i>=0;i--) ans[i] = i%2 == 0 ? e-- : s++;
        for(int i=0;i<N;i++) bw.write(ans[i] + " ");
        
        
        bw.flush();
        bw.close();
    }
    
}