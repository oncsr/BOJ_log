#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;
    
int solution(vector<vector<int>> maps){
    int answer = 0;
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int visit[101][101]{};

    queue<pair<int,int>> q;
    
    int n = maps.size();
    int m = maps[0].size();
    q.push({0,0});
    visit[0][0]++;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        if(x == n - 1 && y == m - 1){
            answer = maps[x][y];
            break;
        }
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(!visit[nx][ny] && maps[nx][ny]){
                    q.push({nx,ny});
                    maps[nx][ny] = maps[x][y] + 1;
                    visit[nx][ny]++;
                }
            }
        }
    }
    if(!answer)
        return -1;
    return answer;
}