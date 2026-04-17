#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int e[10000001]{};
    for(int i=2;i*i<=10000000;i++){
        if(!e[i]){
            for(int j=i*i;j<=10000000;j+=i) e[j] = 1;
        }
    }

    int N, M;
    cin>>N>>M;
    vector<vector<pair<int, ll>>> V(N+1);
    vector<int> arr(N+1);
    for(int i=1;i<=N;i++)   cin>>arr[i];
    for(;M--;){
        int a,b,c;
        cin>>a>>b>>c;
        V[a].emplace_back(b,c);
        V[b].emplace_back(a,c);
    }

    vector<ll> D(N+1, -1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> Q;
    Q.emplace(0, 1);
    D[1] = 0;
    while(!Q.empty()){
        auto [dist, now] = Q.top();
        Q.pop();
        if(dist > D[now])    continue;
        for(auto [next, cost] : V[now]){
            if(e[arr[now] + arr[next]]) continue;
            if(D[next] == -1 || D[next] > dist + cost){
                D[next] = dist + cost;
                Q.emplace(D[next], next);
            }
        }
    }
    if(D[N] == -1)  cout<<"Now where are you?";
    else    cout<<D[N];

}