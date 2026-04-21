#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll res[100] = {0,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,10,2,3,4,5,6,1,2,3,4,5,3,4,5,6,7,2,3,4,5,6,4,5,6,7,8,3,4,5,6,7,2,3,4,5,6,4,5,6,7,8,3,4,5,6,7,5,6,7,8,9,4,5,6,7,8,3,4,5,6,7,5,6,7,8,9,4,5,6,7,8,6,7,8,9,10,5,6,7,8,9};

ll solve(ll N){
    if(N < 100) return res[N];
    return solve(N / 100) + solve(N % 100);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int T;
    for(cin>>T;T--;){
        ll n;
        cin>>n;
        cout<<solve(n)<<'\n';
    }

}