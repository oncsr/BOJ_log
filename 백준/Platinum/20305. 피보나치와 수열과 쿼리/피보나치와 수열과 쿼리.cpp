#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int N, Q;
int f[1000009] = {0,1};
int a[1000009]{};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    for(int i=2;i<1000009;i++) f[i] = (f[i-1] + f[i-2]) % MOD;
    for(cin>>N>>Q;Q--;) {
        int l,r;
        cin>>l>>r;
        a[l] = (a[l] + 1) % MOD;
        a[r+1] = (a[r+1] + MOD - f[r-l+2]) % MOD;
        a[r+2] = (a[r+2] + MOD - f[r-l+1]) % MOD;
    }
    for(int i=2;i<=N;i++) a[i] = (((a[i] + a[i-1]) % MOD) + a[i-2]) % MOD;
    for(int i=1;i<=N;i++) cout<<a[i]<<' ';

}