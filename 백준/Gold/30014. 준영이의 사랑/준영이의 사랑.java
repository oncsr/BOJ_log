import java.util.*;
import java.io.*;

class Main{
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        
        int N = Integer.parseInt(br.readLine());
        int[] A = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0;i<N;i++) A[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(A);
        
        int[] B = new int[N];
        B[0] = A[0];
        int e = N-1, s = 1;
        for(int i=1;i<N;i++){
            if(i%2 == 1)B[s++] = A[i];
            else    B[e--] = A[i];
        }
        
        long ans = 0;
        for(int i=0;i<N;i++){
            ans += (long)B[i] * B[(i+1)%N];
        }
        bw.write(ans+"\n");
        for(int i=0;i<N;i++) bw.write(B[i] + " ");
        
        
        bw.flush();
        bw.close();
    }
    
}