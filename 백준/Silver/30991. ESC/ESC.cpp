#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll a = -1, b = 1, c = 1, n;
    cin>>n;
    for(int i=1;i<n;i++){
        ll ta = a-c, tb = b+c, tc = 2*a-2*b+c;
        a = ta, b = tb, c = tc;
    }
    cout<<a+b+c;

}