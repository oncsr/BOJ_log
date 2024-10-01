#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    // 격자 크기 : 100 * 100
    // 포인트의 수 : 100
    
    for(auto &L : routes)   for(auto &i : L)    i--;
    
    int x[100]{}, y[100]{}, goal[100]{}, pos[101][101]{};
    for(int i=0;i<routes.size();i++){
        auto L = points[routes[i][0]];
        x[i] = L[0], y[i] = L[1], goal[i] = 1;
        pos[L[0]][L[1]]++;
    }
    
    int cnt = 0, ans = 0;
    
    do{
        for(int i=1;i<=100;i++) for(int j=1;j<=100;j++) if(pos[i][j] > 1)   ans++;
        cnt = 0;
        for(int i=0;i<routes.size();i++){
            int &nx = x[i], &ny = y[i];
            if(goal[i] == routes[i].size()){
                pos[nx][ny]--;
                nx = 0, ny = 0;
                pos[nx][ny]++;
                continue;
            }
            cnt++;
            
            pos[nx][ny]--;
            auto L = points[routes[i][goal[i]]];
            int px = L[0], py = L[1];
            if(nx == px){
                if(ny < py) ny++;
                else    ny--;
            }
            else{
                if(nx < px) nx++;
                else    nx--;
            }
            pos[nx][ny]++;
            if(nx == px && ny == py)    goal[i]++;
            
        }
        
        
        
    }while(cnt);

    return ans;
    
}