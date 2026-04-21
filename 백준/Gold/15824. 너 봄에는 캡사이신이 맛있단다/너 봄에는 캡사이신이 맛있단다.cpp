#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll N, g = 1;
    cin>>N;
    vector<ll> arr(N), cf(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
        cf[i] = g;
        g = g*2%mod;
    }
    sort(arr.begin(), arr.end());
    ll ans = 0;
    for(int i=0;i<N;i++)    ans = (ans + cf[i] * arr[i] - cf[N-i-1] * arr[i]) % mod;
    cout<<ans;
    
}