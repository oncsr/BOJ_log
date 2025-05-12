class Solution {
    public int[] solution(int[] sequence, int k) {
        int N = sequence.length;
        int[] answer = {N,2*N};
        
        int s = 0, e = 0, sum = sequence[0];
        while(e<N){
            while(sum > k) sum -= sequence[s++];
            if(sum == k && answer[1]-answer[0] > e-s){
                answer = new int[]{s,e};
            }
            if(++e<N) sum += sequence[e];
        }
        return answer;
    }
}