#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll m = 1e9+7;
ll power(ll a, ll b){
    if(b == 0)  return 1;
    if(b == 1)  return a;
    ll p = power(a, b>>1) % m;
    if(b&1) return p*p%m*a%m;
    return p*p%m;
}

int main(){
    ll A, B;
    cin>>A>>B;
    if(A == 1)  {cout<<B%m;return 0;}
    cout<<((power(A, B) - 1) % m * power(A-1, m-2) % m)%m;
}