import java.util.*;

class Solution {
    class Plan{
        String name;
        int start, duration;
        Plan(String name, int start, int duration){
            this.name = name;
            this.start = start;
            this.duration = duration;
        }
    }
    public String[] solution(String[][] plans) {
        int N = plans.length;
        Plan[] A = new Plan[N];
        for(int i=0;i<N;i++) {
            int start = Integer.parseInt(plans[i][1].substring(0,2)) * 60 + Integer.parseInt(plans[i][1].substring(3,5));
            int duration = Integer.parseInt(plans[i][2]);
            A[i] = new Plan(plans[i][0], start, duration);
        }
        
        Arrays.sort(A, (a,b) -> a.start-b.start);
        String[] result = new String[N];
        int idx = 0;
        Stack<Plan> S = new Stack<>();
        for(int i=0;i<N;i++){
            int diff = A[i].duration;
            if(i<N-1) diff = Math.min(diff, A[i+1].start-A[i].start);
            A[i].duration -= diff;
            if(A[i].duration != 0) S.push(A[i]);
            else {
                result[idx++] = A[i].name;
                int last = A[i].start + diff;
                int nextTime = i==N-1 ? (int)1e9 + 7 : A[i+1].start;
                while(last < nextTime && !S.isEmpty()){
                    Plan recent = S.pop();
                    diff = Math.min(nextTime - last, recent.duration);
                    recent.duration -= diff;
                    last += diff;
                    if(recent.duration != 0) S.push(recent);
                    else result[idx++] = recent.name;
                }
            }
        }
        return result;
    }
}