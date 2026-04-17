#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    vector<ll> V;
    cin>>N;
    for(int i=0;i<N;i++){
        int g;
        ll res = 0;
        for(cin>>g;g--;){
            ll a;
            cin>>a;
            res |= (1LL << a);
        }
        V.emplace_back(res);
    }

    int M;
    for(cin>>M;M--;){
        int g;
        ll res = 0;
        for(cin>>g;g--;){
            ll a;
            cin>>a;
            res |= (1LL << a);
        }
        int ans = 0;
        for(ll i:V){
            ll k = i^res;
            if((k&i) == 0)  ans++;
        }
        cout<<ans<<'\n';
    }
    
}