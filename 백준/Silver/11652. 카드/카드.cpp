#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll N, mx = 0, ans;
    map<ll, int> M;
    for(cin>>N;N--;){
        ll a;
        cin>>a;
        M[a]++;
        if(M[a] > mx || (M[a] == mx && a < ans))    mx = M[a], ans = a;
    }
    cout<<ans;

}