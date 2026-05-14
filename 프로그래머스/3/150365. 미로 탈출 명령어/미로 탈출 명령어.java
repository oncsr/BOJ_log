import java.util.*;

class Solution {
    public static final char[] dir = {'d','l','r','u'};
    public static final int[] dx = {1,0,0,-1};
    public static final int[] dy = {0,-1,1,0};
    
    public String solution(int n, int m, int x, int y, int r, int c, int k) {
        int dist = Math.abs(x-r) + Math.abs(y-c);
        if(k < dist || (k - dist) % 2 == 1) return "impossible";
        String answer = "";
        
        int startDown = n-x;
        int endDown = n-r;
        int startLeft = y-1;
        int endLeft = c-1;
        if(k < startDown + endDown + Math.abs(y-c)) {
            int diff = (k - dist)/2;
            for(int i=0;i<diff + Math.max(0, r-x);i++) {
                answer += "d";
            }
            for(int i=0;i<Math.abs(y-c);i++) {
                answer += (y<c ? "r" : "l");
            }
            for(int i=0;i<diff + Math.max(0, x-r);i++) {
                answer += "u";
            }
        }
        else if(k < startDown + endDown + startLeft + endLeft) {
            int diff = (k - (startDown + endDown + Math.abs(y-c)))/2;
            for(int i=0;i<startDown;i++) {
                answer += "d";
            }
            if(y > c) {
                for(int i=0;i<y-c;i++) {
                    answer += "l";
                }
            }
            for(int i=0;i<diff;i++) {
                answer += "l";
            }
            for(int i=0;i<diff;i++) {
                answer += "r";
            }
            if(c > y) {
                for(int i=0;i<c-y;i++) {
                    answer += "r";
                }
            }
            for(int i=0;i<endDown;i++) {
                answer += "u";
            }
        }
        else {
            int diff = (k - (startDown + startLeft + endDown + endLeft))/2;
            for(int i=0;i<startDown;i++) {
                answer += "d";
            }
            for(int i=0;i<startLeft;i++) {
                answer += "l";
            }
            for(int i=0;i<diff;i++) {
                answer += "rl";
            }
            for(int i=0;i<endLeft;i++) {
                answer += "r";
            }
            for(int i=0;i<endDown;i++) {
                answer += "u";
            }
        }
        
        return answer;
    }
}