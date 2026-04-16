#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, C;
    cin>>N>>C;
    vector<vector<pair<int, int>>> V(N);
    bitset<100000> R;
    for(;C--;){
        int t,a,b;
        cin>>t>>a>>b;
        V[a].emplace_back(b,0);
        if(!t)   R[a] = 1;
    }
    for(int i=0;i<N-1;i++)  if(!R[i])   V[i].emplace_back(i+1,1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
    vector<int> D(N,-1);
    D[0] = 0;
    Q.emplace(0,0);
    while(!Q.empty()){
        auto [d,n] = Q.top();
        Q.pop();
        if(d > D[n])    continue;
        for(auto [i,c]:V[n]){
            if(D[i] == -1 || D[i] > d+c){
                D[i] = d+c;
                Q.emplace(D[i],i);
            }
        }
    }
    cout<<D[N-1];

}