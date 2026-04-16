#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N;
    priority_queue<ll> Q;
    ll H = 0;

    cin>>N;
    vector<pair<ll, ll>> arr(N);
    for(auto &[a,b]:arr)    cin>>a>>b, a+=b;
    sort(arr.begin(), arr.end());

    ll ans = 0;

    for(auto &[l,d]:arr){
        Q.push(d);
        H += d;    
        while(!Q.empty() && l < H){
            H -= Q.top();
            Q.pop();
        }
        ans = max(ans, ll(Q.size()));
    }
    cout<<ans;

}