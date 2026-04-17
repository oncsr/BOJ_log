#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin>>N;
    vector<ll> X(N);
    for(ll &i:X)    cin>>i;
    sort(X.begin(), X.end());
    vector<ll> _1(N);
    for(int i=1;i<N;i++)    _1[i] = _1[i-1] + X[i] - X[i-1];
    vector<ll> _2(N);
    _2[N-1] = _1[N-1];
    for(int i=N-2;i>0;i--)  _2[i] = _2[i+1] + _1[i];
    ll ans = 0, g = N-1;
    for(int i=1;i<N;i++)    ans += _2[i] - _1[i-1] * g--;
    cout<<ans*2;

}