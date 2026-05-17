import java.util.*;

class Solution {
    // 그냥 한 명 골라서 걔로 만들 수 있는 조합 다 해보기
    // N * 2^10 * 
    
    public String[] solution(String[] orders, int[] course) {
        int[] maxOrder = new int[11];
        Set<String>[] result = new Set[11];
        for(int i=2;i<=10;i++) result[i] = new HashSet<>();
        
        int N = orders.length;
        int[] ordersMask = new int[N];
        List<Integer>[] ordersList = new List[N];
        for(int i=0;i<N;i++) {
            ordersList[i] = new ArrayList<>();
            for(char c : orders[i].toCharArray()) {
                ordersMask[i] |= (1<<(c-'A'));
                ordersList[i].add(c-'A');
            }
        }
        
        for(int i=0;i<N;i++) {
            int cur = ordersMask[i];
            for(int j=1;j<(1<<ordersList[i].size());j++) {
                int subCount = 0;
                int subMask = 0;
                for(int k=0;k<ordersList[i].size();k++) if((j & (1<<k)) != 0) {
                    subCount++;
                    subMask |= (1<<ordersList[i].get(k));
                }
                
                if(subCount < 2) continue;
                
                int people = 0;
                for(int k=0;k<N;k++) {
                    int tempCount = 0;
                    for(int g : ordersList[k]) if((subMask & (1<<g)) != 0) {
                        tempCount++;
                    }
                    if(tempCount == subCount) {
                        people++;
                    }
                }
                
                if(people < 2) continue;
                
                if(people > maxOrder[subCount]) {
                    maxOrder[subCount] = people;
                    result[subCount] = new HashSet<>();
                }
                if(people == maxOrder[subCount]) {
                    String str = "";
                    for(int c=0;c<26;c++) if((subMask & (1<<c)) != 0) {
                        str += (char)(c + 'A');
                    }
                    result[subCount].add(str);
                }
            }
        }
        
        int totalSize = 0;
        for(int i : course) totalSize += result[i].size();
        
        String[] answer = new String[totalSize];
        int index = 0;
        for(int i : course) for(String s : result[i]) answer[index++] = s;
        
        Arrays.sort(answer);
        return answer;
    }
}