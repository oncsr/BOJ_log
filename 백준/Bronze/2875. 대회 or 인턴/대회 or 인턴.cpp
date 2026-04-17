#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, M, K;
    cin>>N>>M>>K;
    if(N > 2*M) K -= (N - 2*M), N = 2*M;
    else {
        K -= (M - N/2), M = N/2;
        if(N&1) K--, N--;
    }
    if(K <= 0)  cout<<M;
    else    cout<<max(0, M - ((K-1)/3+1));


}