#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    auto F = [](ll s) -> ll {return s*(s+1)/2;};

    ll a, d, q;
    for(cin>>a>>d>>q;q--;){
        ll o,l,r;
        cin>>o>>l>>r;
        if(o == 1)  cout<<(F(r-1) - F(l-2))*d + (r-l+1)*a<<'\n';
        else{
            if(d == 0)  cout<<a<<'\n';
            else{
                if(l == r)  cout<<a+(l-1)*d<<'\n';
                else    cout<<(a%d?gcd(d,a%d):d)<<'\n';
            }
        }
    }

}