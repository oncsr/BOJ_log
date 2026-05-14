import java.util.*;

class Solution {
    public static final int[] dx = {1,0,-1,0};
    public static final int[] dy = {0,1,0,-1};
    
    public int solution(int[][] board) {
        int R = board.length, C = board[0].length;
        
        boolean[][][] visited = new boolean[R][C][2];
        visited[0][0][0] = true;
        Queue<int[]> queue = new ArrayDeque<>();
        queue.offer(new int[]{0,0,0,0});
        
        int answer = -1;
        while(!queue.isEmpty()) {
            int[] status = queue.poll();
            int x = status[0], y = status[1], isSero = status[2], time = status[3];
            if(isSero == 0 && x == R-1 && y == C-2) {
                answer = time;
                break;
            }
            if(isSero == 1 && x == R-2 && y == C-1) {
                answer = time;
                break;
            }
            
            // move
            for(int i=0;i<4;i++) {
                int xx = x+dx[i], yy = y+dy[i];
                if(isSero == 0) {
                    if(0 <= xx && xx < R && 0 <= yy && yy+1 < C && !visited[xx][yy][isSero] && board[xx][yy] == 0 && board[xx][yy+1] == 0) {
                        visited[xx][yy][isSero] = true;
                        queue.offer(new int[]{xx,yy,isSero,time+1});
                    }
                }
                else {
                    if(0 <= xx && xx+1 < R && 0 <= yy && yy < C && !visited[xx][yy][isSero] && board[xx][yy] == 0 && board[xx+1][yy] == 0) {
                        visited[xx][yy][isSero] = true;
                        queue.offer(new int[]{xx,yy,isSero,time+1});
                    }
                }
            }
            
            // rotate
            if(isSero == 0) {
                if(x+1 < R && board[x+1][y] == 0 && board[x+1][y+1] == 0) {
                    if(!visited[x][y][1]) {
                        visited[x][y][1] = true;
                        queue.offer(new int[]{x,y,1,time+1});
                    }
                    if(!visited[x][y+1][1]) {
                        visited[x][y+1][1] = true;
                        queue.offer(new int[]{x,y+1,1,time+1});
                    }
                }
                if(x-1 >= 0 && board[x-1][y] == 0 && board[x-1][y+1] == 0) {
                    if(!visited[x-1][y][1]) {
                        visited[x-1][y][1] = true;
                        queue.offer(new int[]{x-1,y,1,time+1});
                    }
                    if(!visited[x-1][y+1][1]) {
                        visited[x-1][y+1][1] = true;
                        queue.offer(new int[]{x-1,y+1,1,time+1});
                    }
                }
            }
            else {
                if(y+1 < C && board[x][y+1] == 0 && board[x+1][y+1] == 0) {
                    if(!visited[x][y][0]) {
                        visited[x][y][0] = true;
                        queue.offer(new int[]{x,y,0,time+1});
                    }
                    if(!visited[x+1][y][0]) {
                        visited[x+1][y][0] = true;
                        queue.offer(new int[]{x+1,y,0,time+1});
                    }
                }
                if(y-1 >= 0 && board[x][y-1] == 0 && board[x+1][y-1] == 0) {
                    if(!visited[x][y-1][0]) {
                        visited[x][y-1][0] = true;
                        queue.offer(new int[]{x,y-1,0,time+1});
                    }
                    if(!visited[x+1][y-1][0]) {
                        visited[x+1][y-1][0] = true;
                        queue.offer(new int[]{x+1,y-1,0,time+1});
                    }
                }
            }
        }
        
        return answer;
    }
}