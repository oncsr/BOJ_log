import java.util.*;
import java.io.*;

class Main{
    
    static int ch(String s){
        int res = 1;
        res += 3600*Integer.parseInt(s.substring(0,2));
        res += 60*Integer.parseInt(s.substring(3,5));
        res += Integer.parseInt(s.substring(6,8));
        return res;
    }
    
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int N = Integer.parseInt(br.readLine());
        long[] A = new long[86401];
        long[] S = new long[86401];
        
        boolean flag = false;
        for(int i=0;i<N;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int op = Integer.parseInt(st.nextToken());
            int a = ch(st.nextToken());
            int b = ch(st.nextToken());
            if(op == 1){
                S[a]++;
                S[b]--;
            }
            else{
                if(flag == false){
                    long d = 0;
                    for(int j=1;j<86400;j++){
                        d += S[j];
                        A[j] = A[j-1] + d;
                    }
                    
                    flag = true;
                }
                bw.write((A[b-1]-A[a-1])+"\n");
            }
            
        }
        
        bw.flush();
        bw.close();
    }
}