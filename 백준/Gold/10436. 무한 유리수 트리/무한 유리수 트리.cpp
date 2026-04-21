#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc;
    for(cin>>tc;tc--;){
        ll t, p, q;
        char _;
        cin>>t>>p>>_>>q;
        cout<<t<<' ';
        if(p < q)   cout<<q<<_<<q-p<<'\n';
        else{
            ll cnt = p/q;
            p -= q*cnt;
            ll np = q, nq = q-p;
            p = np, q = nq;
            q += cnt*p;
            cout<<p<<_<<q<<'\n';
        }
    }

}