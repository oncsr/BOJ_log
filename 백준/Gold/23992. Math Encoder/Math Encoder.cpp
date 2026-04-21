#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    vector<ll> cf(10000);
    ll g = 1;
    for(int i=0;i<10000;i++){
        cf[i] = g;
        g = g*2%mod;
    }

    int T, t = 1;
    for(cin>>T;t<=T;t++) {
        ll N;
        cin>>N;
        vector<ll> arr(N);
        for(ll &i:arr)  cin>>i;
        ll ans = 0;
        for(int i=0;i<N;i++)    ans = (ans + cf[i] * arr[i] - cf[N-i-1] * arr[i]) % mod;
        cout<<"Case #"<<t<<": "<<ans<<'\n';
    }
    
}