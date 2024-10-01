#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int cnt = 0, vis[200]{};
    for(int i=0;i<n;i++){
        if(vis[i])  continue;
        queue<int> Q;
        Q.push(i);
        vis[i]++;
        while(!Q.empty()){
            int x = Q.front();
            Q.pop();
            for(int j=0;j<n;j++){
                if(vis[j] || !computers[x][j])  continue;
                vis[j]++;
                Q.push(j);
            }
        }
        cnt++;
    }
    return cnt;
}