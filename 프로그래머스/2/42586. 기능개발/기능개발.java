import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int N = progresses.length;
        
        int[] days = new int[N];
        for(int i=0;i<N;i++) {
            days[i] = (100 - progresses[i] - 1) / speeds[i] + 1;
        }
        
        int max = days[0], count = 1;
        List<Integer> list = new ArrayList<>();
        for(int i=1;i<N;i++) {
            if(days[i] > max) {
                list.add(count);
                max = days[i];
                count = 1;
            }
            else {
                count++;
            }
        }
        
        list.add(count);
        int[] answer = new int[list.size()];
        for(int i=0;i<list.size();i++) {
            answer[i] = list.get(i);
        }
        
        return answer;
    }
}