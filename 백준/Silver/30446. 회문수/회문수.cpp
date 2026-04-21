#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin>>n;
    ll ans = 0;
    ll g = 1;
    ll r = 1;
    ll c = 1;
    ll v = 10;
    while(v * g + r <= n){
        ans++;
        g++;
        string temp = to_string(g);
        reverse(temp.begin(), temp.end());
        r = stol(temp);
        if(g == v)   v *= 10;
    }
    ans += min(9LL, n);
    g = 10, r = 1, c = 1, v = 10;
    while(v * g + r <= n){
        ans++;
        g++;
        string temp = to_string(g);
        temp.pop_back();
        reverse(temp.begin(), temp.end());
        r = stol(temp);
        if(g == v*10)   v *= 10;
    }
    cout<<ans;
}