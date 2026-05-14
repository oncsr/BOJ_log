class Solution {
    public int isValid(char[][] place) {
        for(int i=0;i<5;i++) for(int j=0;j<5;j++) if(place[i][j] == 'P') {
            for(int x=i;x<5;x++) for(int y=0;y<5;y++) if((i != x || j != y) && place[x][y] == 'P') {
                if(i == x && y < j) continue;
                
                int dist = Math.abs(i-x) + Math.abs(j-y);
                if(dist > 2) continue;
                if(dist == 1) return 0;
                if(i == x) {
                    if(place[i][j+1] != 'X') return 0;
                }
                else if(j == y) {
                    if(place[i+1][j] != 'X') return 0;
                }
                else {
                    if(place[i+1][j] != 'X') return 0;
                    if(j+1 == y && place[i][j+1] != 'X') return 0;
                    if(j-1 == y && place[i][j-1] != 'X') return 0;
                }
            }
        }
        
        
        return 1;
    } 
    
    public int[] solution(String[][] places) {
        int[] answer = new int[5];
        
        for(int i=0;i<5;i++) {
            char[][] temp = new char[5][5];
            for(int j=0;j<5;j++) temp[j] = places[i][j].toCharArray();
            answer[i] = isValid(temp);
        }
        
        return answer;
    }
}