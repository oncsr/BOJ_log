#include <bits/stdc++.h>
using namespace std;
 
int N, M, K;
int F[700][700]{};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M>>K;
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) cin>>F[i][j];
    
    int s = 0, e = 1e9+1, m = (s+e)>>1;
    while(s<e){
        deque<tuple<int,int,int>> D;
        D.emplace_back(0,0,0);
        bool V[700][700]{};
        V[0][0] = 1;
        int res = 0;
        while(!D.empty()){
            auto [x,y,t] = D.front();
            D.pop_front();
            res = t;
            if(x==N-1 && y==M-1) break;
            for(int i=0;i<4;i++){
                int xx = x+dx[i], yy = y+dy[i];
                if(xx<0 || xx>=N || yy<0 || yy>=M || V[xx][yy]) continue;
                V[xx][yy] = 1;
                if(F[xx][yy] > m) D.emplace_back(xx,yy,t+1);
                else D.emplace_front(xx,yy,t);
            }
        }
        if(res <= K) e = m;
        else s=m+1;
        m = (s+e)>>1;
    }
    cout<<m;
    
}
