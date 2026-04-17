#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    auto fac = [](ll a) -> ll {
        ll res = 1;
        while(a > 0)    res *= a--;
        return res;
    };
    cout<<fac(n)/fac(a)/fac(b)/fac(c);

}