#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll N, K, ans = 0;
    vector<pair<ll, ll>> give;
    vector<pair<ll, ll>> take;
    cin>>N>>K;
    for(int i=0;i<N;i++){
        ll a;
        cin>>a;
        if(a > K)   give.push_back({i,a-K});
        if(a < K)   take.push_back({i,K-a});
    }
    ll pos1 = 0, pos2 = 0;
    while(pos1 < give.size()){
        ll v = min(give[pos1].second, take[pos2].second);
        give[pos1].second-=v;
        take[pos2].second-=v;
        ans += v*abs(give[pos1].first - take[pos2].first);
        if(give[pos1].second == 0)  pos1++;
        if(take[pos2].second == 0)  pos2++;
    }
    cout<<ans;
}