import java.util.*;
import java.io.*;

class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int N = Integer.parseInt(br.readLine());
        ArrayList<Integer> odd = new ArrayList<>();
        ArrayList<Integer> even = new ArrayList<>();
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0;i<N;i++){
            int a = Integer.parseInt(st.nextToken());
            if(a%2 == 0) even.add(a);
            else odd.add(a);
        }
        Collections.sort(odd);
        Collections.sort(even);
        
        int A = 1, B = 2;
        for(int i:odd){
            if(i != A) break;
            A += 2;
        }
        for(int i:even){
            if(i != B) break;
            B += 2;
        }
        if(odd.size() == even.size()) bw.write(Math.min(A, B)+"\n");
        else if(odd.size() > even.size()) bw.write(A+"\n");
        else bw.write(B+"\n");
        
        bw.flush();
        bw.close();
    }
}