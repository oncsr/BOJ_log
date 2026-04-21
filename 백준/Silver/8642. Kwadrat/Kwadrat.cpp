#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    ll n;
    cin>>n;
    ll ans = n;

    int cnt[22362]{};
    for(int i=2;i*i<=n;i++){
        while(n%i == 0){
            cnt[i]++;
            n/=i;
        }
    }
    if(n > 1)   ans *= n;

    for(int i=1;i<=22361;i++){
        if(cnt[i]&1)    ans *= (ll)i;
    }
    cout<<ans;
    
}