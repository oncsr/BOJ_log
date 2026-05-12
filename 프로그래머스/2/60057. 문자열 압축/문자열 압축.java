class Solution {
    public int solution(String s) {
        int minLength = s.length();
        for(int i=1;i<=s.length();i++) {
            int resultLength = 0;
            String base = "";
            int count = 0;
            for(int j=0;j<s.length();j+=i) {
                String sub = s.substring(j, Math.min(j+i, s.length()));
                if(sub.equals(base)) {
                    count++;
                }
                else {
                    if(count > 1) {
                        resultLength += Integer.toString(count).length();
                    }
                    resultLength += base.length();
                    base = sub;
                    count = 1;
                }
            }
            if(count > 1) {
                resultLength += Integer.toString(count).length();
            }
            resultLength += base.length();
            
            minLength = Math.min(minLength, resultLength);
        }
        
        return minLength;
    }
}