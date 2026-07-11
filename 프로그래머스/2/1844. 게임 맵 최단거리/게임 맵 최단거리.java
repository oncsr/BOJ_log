import java.util.*;

class Solution {
    public static final int[] dx = {1,0,-1,0};
    public static final int[] dy = {0,1,0,-1};
    
    public int solution(int[][] maps) {
        if(maps[0][0] == 0) return -1;
        
        int R = maps.length, C = maps[0].length;
        
        boolean[][] visited = new boolean[R][C];
        visited[0][0] = true;
        Queue<int[]> queue = new ArrayDeque<>();
        queue.offer(new int[]{0, 0, 1});
        while(!queue.isEmpty()) {
            int[] status = queue.poll();
            int x = status[0], y = status[1], count = status[2];
            if(x == R-1 && y == C-1) return count;
            for(int i=0;i<4;i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if(0 <= xx && xx < R && 0 <= yy && yy < C && !visited[xx][yy] && maps[xx][yy] == 1) {
                    visited[xx][yy] = true;
                    queue.offer(new int[]{xx, yy, count+1});
                }
            }
        }
        
        return -1;
    }
}