#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll F(ll n){
    return n*(n+1)/2;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    ll N, K, T;
    for(cin>>T;T--;){
        cin>>N>>K;
        cout<<4*(F(N)-F(max(0LL,N-K-1)))<<'\n';
    }
    
}