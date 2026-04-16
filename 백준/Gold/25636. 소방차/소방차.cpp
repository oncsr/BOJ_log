#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
using ll = long long;

struct cmp{
    bool operator()(tuple<ll,ll,int> b, tuple<ll,ll,int> a){
        if(get<0>(a) == get<0>(b)) return get<1>(a) > get<1>(b);
        return get<0>(a) < get<0>(b);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    const ll INF = 1e18 + 7;

    int N,M;
    vector<vector<pair<int, ll>>> V(100001);
    vector<int> A(100001);
    cin>>N;
    for(int i=1;i<=N;i++) cin>>A[i];
    for(cin>>M;M--;){
        int a,b,c;
        cin>>a>>b>>c;
        V[a].emplace_back(b,c);
        V[b].emplace_back(a,c);
    }

    int S, T;
    cin>>S>>T;
    vector<ll> D(100001, INF);
    vector<ll> C(100001, 0);
    priority_queue<tuple<ll,ll,int>, vector<tuple<ll,ll,int>>, cmp> Q;
    Q.emplace(0,A[S],S);
    D[S] = 0;
    C[S] = A[S];
    while(!Q.empty()){
        auto [d,c,n] = Q.top(); Q.pop();
        if(d > D[n] || (d == D[n] && c < C[n])) continue;
        for(auto [i,k]:V[n]){
            if(D[i] > d+k || (D[i] == d+k && C[i] < c+A[i])){
                D[i] = d+k;
                C[i] = c+A[i];
                Q.emplace(D[i],C[i],i);
            }
        }
    }
    if(D[T] == INF) cout<<"-1";
    else cout<<D[T] << ' '<<C[T];

}