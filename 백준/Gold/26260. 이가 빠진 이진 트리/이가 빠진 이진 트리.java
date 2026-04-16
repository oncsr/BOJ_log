import java.util.*;
import java.io.*;

class Main{
    
    static int[] arr;
    
    static BufferedReader br;
    static BufferedWriter bw;
    
    public static void sol(int l, int r) throws Exception{
        if(l == r) bw.write(arr[l] + " ");
        else{
            int m = (l+r)/2;
            sol(l,m-1);
            sol(m+1,r);
            bw.write(arr[m] + " ");
        }
    }
    
    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int N = Integer.parseInt(br.readLine());
        arr = new int[N];
        int idx = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0;i<N;i++){
            arr[i] = Integer.parseInt(st.nextToken());
            if(arr[i] == -1) idx = i;
        }
        arr[idx] = Integer.parseInt(br.readLine());
        Arrays.sort(arr);
        
        sol(0,N-1);
        
        bw.flush();
        bw.close();
    }
    
}