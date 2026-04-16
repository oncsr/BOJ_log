#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N,S,D,F,B,K;
    cin>>N>>S>>D>>F>>B>>K;
    int vis[100001]{};
    for(int i=0,a;i<K;i++)  cin>>a, vis[a]++;
    queue<pair<int,int>> Q;
    Q.emplace(S,0);
    vis[S]++;
    while(!Q.empty()){
        auto [n,t]=Q.front();Q.pop();
        if(n == D)  return cout<<t,0;
        if(n+F <= N && !vis[n+F])   vis[n+F]++,Q.emplace(n+F,t+1);
        if(n-B > 0 && !vis[n-B])    vis[n-B]++,Q.emplace(n-B,t+1);
    }
    cout<<"BUG FOUND";

}