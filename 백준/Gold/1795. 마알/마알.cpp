#include <bits/stdc++.h>
using namespace std;

int main(){
   cin.tie(0)->sync_with_stdio(0);

   int N, M;
   cin>>N>>M;
   char arr[10][10]{};
   int ans[10][10]{};
   int dx[8] = {1,2,2,1,-1,-2,-2,-1};
   int dy[8] = {2,1,-1,-2,2,1,-1,-2};
   for(int i=0;i<N;i++) for(int j=0;j<M;j++){
      char a;
      cin>>a;
      if(a == '.')   continue;
      int k = a-'0';
      int vis[10][10]{};
      queue<tuple<int, int, int>> Q;
      Q.emplace(i,j,0);
      vis[i][j]++;
      while(!Q.empty()){
         auto [x,y,t] = Q.front();
         int T = (t%k ? t/k+1 : t/k);
         if(ans[x][y] != -1)   ans[x][y] += T;
         Q.pop();
         for(int d=0;d<8;d++){
            int xx = x+dx[d], yy = y+dy[d];
            if(xx<0 || xx>=N || yy<0 || yy>=M || vis[xx][yy])  continue;
            vis[xx][yy]++;
            Q.emplace(xx,yy,t+1);
         }
      }
      for(int x=0;x<N;x++) for(int y=0;y<M;y++){
         if(!vis[x][y]){
            ans[x][y] = -1;
         }
      }

   }
   int mn = 1e8;
   for(int i=0;i<N;i++) for(int j=0;j<M;j++){
      if(ans[i][j] == -1)  continue;
      mn = min(mn, ans[i][j]);
   }
   cout<<(mn == 1e8 ? -1 : mn);

}