#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll N, M;
    cin>>N>>M;
    bool ans = 0;
    ll L = N, R = N;
    if(M == 1 || M == N){cout<<"YES";return 0;}
    while(R > 1){
        L >>= 1;
        if(R&1) R = (R>>1)+1;
        else    R >>= 1;
        ans |= (L <= M && M <= R);
    }
    cout<<(ans?"YES":"NO");
    
}