import java.util.*;
import java.io.*;

class Main{
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        
        if(N == M)  bw.write("-1");
        else{
            for(int i=1;i<K;i++) bw.write(i + " ");
            for(int i=N;i>M;i--) bw.write(i + " ");
            for(int i=K;i<=M;i++) bw.write(i + " ");
        }
        
        bw.flush();
        bw.close();
    }
    
}