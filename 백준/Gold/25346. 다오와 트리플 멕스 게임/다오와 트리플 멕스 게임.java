import java.util.*;
import java.io.*;

class Main{
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        
        int N = Integer.parseInt(br.readLine());
        TreeSet<Integer> S = new TreeSet<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int nonzero = 0;
        for(int i=0;i<N;i++){
            int a = Integer.parseInt(st.nextToken());
            if(a > 0) nonzero++;
            S.add(a);
        }
        int mex = 0;
        for(int i:S){
            if(i == mex) mex++;
            else break;
        }
        if(mex == 0) bw.write("0");
        else {
            if(nonzero > 0) bw.write((mex+2)+"\n");
            else    bw.write("1");
        }
        
        
        bw.flush();
        bw.close();
    }
    
}