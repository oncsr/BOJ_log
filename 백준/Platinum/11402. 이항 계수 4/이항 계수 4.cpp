#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll M;

ll power(ll n, ll k){
    if(k == 0)  return 1;
    if(k == 1)  return n % M;
    ll p = power(n,k>>1) % M;
    if(k&1) return p*p%M*n%M;
    return p*p%M;
}

ll comb(ll n, ll k){
    ll H = 1, L = 1, a = n, b = 1;
    for(ll j = 1; j <= min(k, n-k); j++){
        H = (H * a--) % M;
        L = (L * b++) % M;
    }
    return H * power(L, M-2) % M;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, K;
    cin>>N>>K>>M;
    if(M == 2){
        if(K == 0 || (K == 1 && (N&1))) cout<<1;
        else    cout<<0;
        return 0;
    }

    ll ans = 1;
    while(N){
        ll n = N % M, k = K % M;
        ll v = (n < k ? 0 : comb(n,k));
        ans = (ans * v) % M;
        N = (N-n)/M, K = (K-k)/M;
    }
    cout<<ans;

}