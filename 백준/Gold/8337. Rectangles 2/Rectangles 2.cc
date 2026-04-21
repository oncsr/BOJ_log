#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll n, ans = 0;
    cin>>n;
    for(ll i=1;i*i<=n;i++)  ans += n/i - (i-1);
    cout<<ans;

}