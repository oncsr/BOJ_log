class Solution {
    public int convertTimeToInteger(String time) {
        String[] splitedTime = time.split(":");
        int hour = Integer.parseInt(splitedTime[0]);
        int minute = Integer.parseInt(splitedTime[1]);
        int second = Integer.parseInt(splitedTime[2]);
        return second + minute*60 + hour*60*60;
    }
    
    public String convertTimeToString(int time) {
        int hour = time / (60 * 60);
        time -= hour * 60 * 60;
        int minute = time / 60;
        time -= minute * 60;
        int second = time;
        
        String ret = "";
        if(hour < 10) ret += "0";
        ret += Integer.toString(hour);
        ret += ":";
        if(minute < 10) ret += "0";
        ret += Integer.toString(minute);
        ret += ":";
        if(second < 10) ret += "0";
        ret += Integer.toString(second);
        
        return ret;
    }
    
    public String solution(String play_time, String adv_time, String[] logs) {
        int size = convertTimeToInteger(play_time);
        int adLen = convertTimeToInteger(adv_time);
        long[] count = new long[size + 2];
        
        for(String log : logs) {
            String[] splitedLog = log.split("-");
            int start = convertTimeToInteger(splitedLog[0]);
            int end = convertTimeToInteger(splitedLog[1]);
            
            count[start]++;
            count[end]--;
        }
        
        long sum = 0;
        for(int i=1;i<=size;i++) {
            sum += count[i];
            count[i] = count[i-1] + sum;
        }
        
        int maxTime = 0;
        long maxCount = count[adLen-1];
        for(int i=adLen;i<=size;i++) {
            long curCount = count[i] - count[i - adLen];
            if(curCount > maxCount) {
                maxTime = i - adLen + 1;
                maxCount = curCount;
            }
        }
        
        return convertTimeToString(maxTime);
    }
}