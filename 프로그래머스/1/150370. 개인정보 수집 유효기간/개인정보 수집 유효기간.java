import java.util.*;

class Solution {
    public int dateToInteger(String date) {
        String[] sp = date.split("\\.");
        int year = Integer.parseInt(sp[0]);
        int month = Integer.parseInt(sp[1]);
        int day = Integer.parseInt(sp[2]);
        
        int ret = (day-1) + (month-1) * 28 + year * 28 * 12;
        return ret;
    }
    
    public int[] solution(String today, String[] terms, String[] privacies) {
        int todayValue = dateToInteger(today);
        
        int[] limit = new int[128];
        for(String term : terms) {
            String[] sp = term.split(" ");
            char type = sp[0].charAt(0);
            limit[type] = Integer.parseInt(sp[1]);
        }
        
        List<Integer> list = new ArrayList<>();
        for(int i=0;i<privacies.length;i++) {
            String privacy = privacies[i];
            
            String[] sp = privacy.split(" ");
            String date = sp[0];
            char type = sp[1].charAt(0);
            
            int privacyDateValue = dateToInteger(date);
            if(todayValue >= privacyDateValue + limit[type] * 28) {
                list.add(i+1);
            }
        }
        
        int[] answer = new int[list.size()];
        for(int i=0;i<list.size();i++) {
            answer[i] = list.get(i);
        }
        
        return answer;
    }
}