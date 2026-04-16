import java.util.*;
import java.io.*;

class Main{
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        long N = Long.parseLong(br.readLine());
        
        int c = 0;
        for(long i=2;i*i<=N;i++){
            while(N%i == 0){
                c++;
                N/=i;
            }
        }
        if(N != 1)  c++;
        if(c == 2) bw.write("cubelover");
        else    bw.write("koosaga");
        
        bw.flush();
        bw.close();
    }
    
}