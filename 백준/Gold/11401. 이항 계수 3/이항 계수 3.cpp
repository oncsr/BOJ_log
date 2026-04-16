#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
ll fact[4000001] = {1};
ll N, K;

ll power(ll a, ll b) {
    if(b == 0) return 1;
    if(b == 1) return a % MOD;
    ll h = power(a, b>>1) % MOD;
    h = (h * h) % MOD;
    return (b&1) ? h*a%MOD : h;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	for(int i=1;i<=4000000;i++) fact[i] = (fact[i-1] * i) % MOD;

    cin>>N>>K;
    cout<<fact[N] * power(fact[K], MOD-2) % MOD * power(fact[N-K], MOD-2) % MOD;

}