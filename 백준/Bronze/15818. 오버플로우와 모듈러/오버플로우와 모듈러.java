import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        long M = Long.parseLong(st.nextToken());
        
        st = new StringTokenizer(br.readLine());
        long S = 1;
        for(int i=0;i<N;i++){
            S = (S * Long.parseLong(st.nextToken())) % M;
        }
        bw.write(S+"\n");
        
        
        bw.flush();
        bw.close();
    }
}