#include <bits/stdc++.h>
#include <random>
#include <cstdint>
using namespace std;
using ll = long long;

vector<ll> res;

ll gcd(ll a, ll b){
    if(!a)  return b;
    if(!b)  return a;
    if(a < b)   swap(a,b);
    return a%b?gcd(b, a%b):b;
}

ll power(ll n, ll p, ll m){
    if(p == 0)  return 1;
    if(p == 1)  return n;
    __int128 r = 1;
    while(p){
        if(p&1) r = r * n % m;
        n = (__int128)n*n%m;
        p >>= 1;
    }
    return r;
}

bool miller_rabin(ll n){
    if(n <= 1)  return false;
    if(n <= 3)  return true;
    if(!(n&1))  return false;

    for(auto &a : {2,3,5,7,11,13,17,19,23,29,31,37}){
        if(n == a)    return true;
        if(a >= n-1)  return true;
        ll T = (n-1)>>1;

        bool may_prime = 0;
        while(!(T&1)){
            if(power(a, T, n) == n-1) {may_prime=1; break;}
            T >>= 1;
        }
        ll v = power(a, T, n);
        if(v == n-1 || v == 1)  may_prime = 1;

        if(!may_prime)  return false;
    }
    return true;
    
}

void rho(ll n){
    if(n == 1)  return;
    if(!(n&1))  {res.push_back(2); rho(n >> 1); return;}

    if(miller_rabin(n)) {res.push_back(n); return;}

    ll c, x, y, v;
    c = rand() % 20 + 1;
    x = y = rand() % (n-2) + 2;

    auto f = [&](ll g){return ((__int128)g*g + c)%n;};
    do x = f(x), y = f(f(y)), v = gcd(abs(y-x), n);
    while(v == 1);
    
    rho(v);

    rho(n/v);
    
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin>>n;
    rho(n);
    ll ans = n;
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

    for(auto i:res){
        ans /= i;
        ans *= (i-1);
    }
    cout<<ans;

}