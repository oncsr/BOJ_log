import java.util.*;

class Solution {
    public int N;
    public int[] left, right, parent;
    public boolean[] dp;
    
    public boolean isValidMasking(int mask) {
        if((mask & 1) == 0) return false;
        
        Queue<Integer> queue = new ArrayDeque<>();
        queue.add(0);
        int result = 0;
        while(!queue.isEmpty()) {
            int cur = queue.poll();
            result |= (1<<cur);
            if(left[cur] != -1 && (mask & (1<<left[cur])) != 0) {
                queue.offer(left[cur]);
            }
            if(right[cur] != -1 && (mask & (1<<right[cur])) != 0) {
                queue.offer(right[cur]);
            }
        }
        return result == mask;
    }
    
    public List<Integer> findLeaves(int mask) {
        List<Integer> leaves = new ArrayList<>();
        for(int i=0;i<N;i++) if((mask & (1<<i)) != 0) {
            boolean L = left[i] == -1 || (mask & (1<<left[i])) == 0;
            boolean R = right[i] == -1 || (mask & (1<<right[i])) == 0;
            if(L && R) leaves.add(i);
        }
        return leaves;
    }
    
    public int count(int mask, int type, int[] info) {
        int ret = 0;
        for(int i=0;i<N;i++) if((mask & (1<<i)) != 0) {
            if(info[i] == type) ret++;
        }
        return ret;
    }
    
    public int solution(int[] info, int[][] edges) {
        N = info.length;
        left = new int[N];
        right = new int[N];
        parent = new int[N];
        Arrays.fill(left, -1);
        Arrays.fill(right, -1);
        Arrays.fill(parent, -1);
        for(int[] edge : edges) {
            int par = edge[0], child = edge[1];
            if(left[par] == -1) {
                left[par] = child;
            }
            else {
                right[par] = child;
            }
            parent[child] = par;
        }
        
        dp = new boolean[1<<N];
        dp[1] = true;
        
        int answer = 1;
        for(int x=2;x<(1<<N);x++) if(isValidMasking(x) && count(x, 0, info) - count(x, 1, info) > 0) {
            List<Integer> leaves = findLeaves(x);
            for(int leaf : leaves)  dp[x] |= dp[x ^ (1<<leaf)];
            if(dp[x]) {
                answer = Math.max(answer, count(x, 0, info));
            }
        }
        
        return answer;
    }
}