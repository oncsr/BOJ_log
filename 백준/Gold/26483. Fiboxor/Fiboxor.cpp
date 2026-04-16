#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll K, F[2000001] = {0,1}, X[2000001] = {0,1}, c;

void init(int q) {
    K = 1LL<<20;
    for(int i=2;i<=2000000;i++)    F[i] = (F[i-1] + F[i-2])%K, X[i] = X[i-1] ^ F[i];
}

int s(ll x){
    if(x < 0)    return 0;
    if(((x+1)/c)&1)    return X[x%c] ^ X[c-1];
    return X[x%c];
}

int query(int k, long long l, long long r) {
    K = 1LL<<k, c = 3*(1<<(k-1));
    return (s(r) ^ s(l-1)) % K;
}
