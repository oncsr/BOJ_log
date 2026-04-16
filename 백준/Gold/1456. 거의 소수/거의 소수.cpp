#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll A, B;
    cin>>A>>B;
    bitset<10000001> e;
    ll ans = 0;
    for(ll i=2;i*i<=10000000;i++){
        if(!e[i]){
            for(ll j=i*i;j<=10000000;j+=i)    e[j]=1;
        }
    }
    for(ll i=2;i<=10000000;i++) if(!e[i]){
        ll j=i;
        while(j <= B/i){
            j*=i;
            if(j >= A)  ans++;
        }
    }
    cout<<ans;

}