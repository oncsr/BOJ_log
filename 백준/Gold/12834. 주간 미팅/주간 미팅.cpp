#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dijk(int s, vector<int> &D, vector<vector<pair<int, int>>> &V){
    D[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
    Q.emplace(0,s);
    while(!Q.empty()){
        auto [d,n] = Q.top();
        Q.pop();
        if(d > D[n])    continue;
        for(auto [x,c] : V[n]){
            if(D[x] == -1 || D[x] > d+c){
                D[x] = d+c;
                Q.emplace(D[x],x);
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n,v,e,A,B;
    cin>>n>>v>>e>>A>>B;
    vector<vector<pair<int, int>>> V(v+1);
    vector<int> H(n);
    for(int &i:H)   cin>>i;

    for(;e--;){
        int a,b,c;
        cin>>a>>b>>c;
        V[a].emplace_back(b,c);
        V[b].emplace_back(a,c);
    }

    vector<int> D1(v+1,-1), D2(v+1,-1);
    dijk(A, D1, V);    dijk(B, D2, V);
    int ans = 0;
    for(int i:H)    ans += D1[i]+D2[i];
    cout<<ans;

}