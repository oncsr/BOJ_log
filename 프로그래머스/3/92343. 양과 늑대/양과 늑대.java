import java.util.*;

class Solution {
    public int N;
    public List<Integer>[] tree;
    
    public int comb(boolean[] visited, int sheep, int wolf, int[] info) {
        int ret = sheep;
        for(int i=0;i<N;i++) if(!visited[i]) {
            boolean canGo = false;
            for(int j : tree[i]) canGo |= visited[j];
            
            if(canGo) {
                if(info[i] == 1 && wolf + 1 >= sheep) continue;
                
                if(info[i] == 1) wolf++;
                else sheep++;
                visited[i] = true;
                ret = Math.max(ret, comb(visited, sheep, wolf, info));
                
                if(info[i] == 1) wolf--;
                else sheep--;
                visited[i] = false;
            }
        }
        return ret;
    }
    
    public int solution(int[] info, int[][] edges) {
        N = info.length;
        tree = new List[N];
        for(int i=0;i<N;i++) tree[i] = new ArrayList<>();
        for(int[] edge : edges) {
            int a = edge[0], b = edge[1];
            tree[a].add(b);
            tree[b].add(a);
        }
        
        boolean[] visited = new boolean[N];
        visited[0] = true;
        return comb(visited, 1, 0, info);
    }
}