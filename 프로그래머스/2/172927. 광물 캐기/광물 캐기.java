class Solution {
    static int min = (int)1e9 + 7;
    public void bck(int pos, int tir, int[] picks, String[] minerals){
        for(int k=0;k<3;k++)if(picks[k] > 0){
            picks[k]--;
            int c = 0;
            for(int i=pos;i<Math.min(pos+5,minerals.length);i++){
                if(minerals[i].equals("diamond")){
                    if(k == 0) c++;
                    else if(k == 1) c+=5;
                    else c+=25;
                }
                else if(minerals[i].equals("iron")){
                    if(k <= 1) c++;
                    else c+=5;
                }
                else c++;
            }
            if(pos+5 <= minerals.length && picks[0] + picks[1] + picks[2] > 0) bck(pos+5, tir+c, picks, minerals);
            else min = Math.min(min, tir+c);
            picks[k]++;
        }
        
    }
    
    public int solution(int[] picks, String[] minerals) {
        bck(0,0,picks, minerals);
        return min;
    }
}