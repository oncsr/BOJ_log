#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll ans = 0, n;
    stack<ll> S;
    for(cin>>n;n--;){
        ll a;
        cin>>a;
        while(!S.empty() && a >= S.top()){
            ll temp = S.top();
            S.pop();
            if(S.empty() || a < S.top()){
                ans += a - temp;
                break;
            }
            ans += S.top() - temp;
        }
        S.push(a);
    }
    while(!S.empty()){
        ll temp = S.top();
        S.pop();
        if(S.empty())   break;
        ans += S.top() - temp;
    }
    cout<<ans;

}