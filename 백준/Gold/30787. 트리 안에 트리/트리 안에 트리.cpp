#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll mod = 1e9+7, n, k;
    cin>>n>>k;
    ll ans = 1;
    ll V = 2;
    for(int i=1;i<=n-k;i++){
        if(i >= k && i <= n-k)  ans += V*3;
        else    ans += V;
        V = (V*2)%mod;
        ans %= mod;
    }
    cout<<ans;
}