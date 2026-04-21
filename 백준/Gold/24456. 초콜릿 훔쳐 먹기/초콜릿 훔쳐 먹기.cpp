#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N, M, K, i = 1;
    cin>>N>>M>>K;
    int D_old = abs(N-M);
    for(;i<N*M;i++){
        bool f = abs(N*M-2 - D_old) <= K;
        for(int j=2;j*j<=N*M-i;j++){
            if(f)   break;
            if((N*M-i)%j)   continue;
            f |= abs((N*M-i)/j - j - D_old) <= K;
        }
        if(!f)  {cout<<i-1; break;}
    }
    if(i == N*M) cout<<N*M-1;
}