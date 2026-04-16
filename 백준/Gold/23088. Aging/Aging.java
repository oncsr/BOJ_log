import java.util.*;
import java.io.*;

class Job{
    int prior;
    int time;
    int num;
    int call;
    Job(int prior, int time, int num, int call){
        this.prior = prior;
        this.time = time;
        this.num = num;
        this.call = call;
    }
}
    
class Main{
    
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int N = Integer.parseInt(br.readLine());
        
        Job[] arr = new Job[N];
        for(int i=1;i<=N;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            int p = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            arr[i-1] = new Job(p-t, b, i, t);
        }
        
        PriorityQueue<Job> PQ = new PriorityQueue<>((a, b) -> {
            if(a.prior == b.prior){
                if(a.time == b.time) return a.num - b.num;
                return a.time - b.time;
            }
            return b.prior - a.prior;
        });
        PQ.offer(arr[0]);
        int time = arr[0].call;
        int i=1;
        while(i<N || !PQ.isEmpty()){
            while(i<N && arr[i].call <= time) PQ.offer(arr[i++]);
            Job cur = PQ.poll();
            bw.write(cur.num + " ");
            time += cur.time;
        }
        while(!PQ.isEmpty()){
            bw.write(PQ.poll().num + " ");
        }
        
        
        bw.flush();
        bw.close();
    }
}