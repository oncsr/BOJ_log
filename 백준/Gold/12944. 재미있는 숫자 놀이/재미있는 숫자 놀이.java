import java.util.*;
import java.io.*;

class Main{
    
    public static long gcd(long a, long b){
        if(a < b){
            if(b%a == 0) return a;
            return gcd(a,b%a);
        }
        else{
            if(a%b == 0) return b;
            return gcd(b,a%b);
        }
    }
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        StringTokenizer st1 = new StringTokenizer(br.readLine());
        StringTokenizer st2 = new StringTokenizer(br.readLine());
        
        long N = Long.parseLong(st1.nextToken());
        int K = Integer.parseInt(st1.nextToken());
        
        long[] arr = new long[K];
        for(int i=0;i<K;i++) arr[i] = Long.parseLong(st2.nextToken());
        
        long ans = N/arr[0];
        ArrayList<Long> A = new ArrayList<>();
        ArrayList<Integer> C = new ArrayList<>();
        A.add(arr[0]);
        C.add(1);
        for(int i=1;i<K;i++){
            ans += N/arr[i];
            for(int j=0,p=A.size();j<p;j++){
                long g = A.get(j) * arr[i] / gcd(A.get(j), arr[i]);
                if(g > N) continue;
                long v = N / g;
                if(C.get(j) % 2 == 1) v *= -1;
                ans += v;
                A.add(g);
                C.add(C.get(j)+1);
            }
            A.add(arr[i]);
            C.add(1);
        }
        bw.write(ans+"\n");
        
        bw.flush();
        bw.close();
    }
    
}