#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    ll N, C, W;
    cin>>N>>C>>W;
    ll arr[50]{};
    for(int i=0;i<N;i++)    cin>>arr[i];
    ll ans = 0;
    for(ll k=1;k<=10000;k++){
        ll cut = 0, wood = 0;
        for(int i=0;i<N;i++){
            ll ncut = (arr[i] - 1) / k;
            ll nwood = arr[i] / k;
            if(nwood * k * W - ncut * C >= 0)   cut += ncut, wood += nwood;
        }
        ans = max(ans, wood*k*W - C*cut);
        wood = 0;
        for(int i=0;i<N;i++){
            if(k == arr[i]) wood++;
        }
        ans = max(ans, wood*k*W);
    }
    cout<<ans;
    
}