import java.util.*;
import java.io.*;

class Main{
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        long N = Long.parseLong(br.readLine());
        while(N != 0L){
            boolean pos = N > 0L;
            long R = Math.abs(N);
            boolean suc = false;
            for(int i=31;i>1;i--){
                for(long k=2L;;k++){
                    long g = 1L;
                    boolean over = false;
                    for(int p=0;p<i;p++){
                        g*=k;
                        if(g > R) {
                            over = true;
                            break;
                        }
                    }
                    if(over) break;
                    if(g == R){
                        if(i%2 == 0 && pos == false){
                            continue;
                        }
                        else{
                            bw.write(i + "\n");
                            suc = true;
                            break;
                        }
                    }
                }
                if(suc) break;
            }
            
            // 1
            if(suc == false) bw.write("1\n");
            N = Long.parseLong(br.readLine());
        }
        
        bw.flush();
        bw.close();
    }
    
}