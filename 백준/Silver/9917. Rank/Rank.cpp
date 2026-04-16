#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, k, e[21][21]{};
    for(cin>>n>>k;k--;){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(c>d) e[a][b] = 1;
        else    e[b][a] = 1;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        int vis[21]{};
        vis[i]++;
        queue<int> Q;
        Q.push(i);
        bool br = 0;
        while(!Q.empty()){
            int g = Q.front();  Q.pop();
            for(int j=1;j<=n;j++){
                if(!e[g][j])    continue;
                if(j == i)  {br=1;break;}
                if(vis[j])  continue;
                Q.push(j);
                vis[j]++;
            }
            if(br)  break;
        }
        if(br)  ans++;

    }
    cout<<ans;

}