#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin>>N;
    for(int i=0;i<(N+1)/2;i++)  cout<<1+i*2<<' ';
    for(int i=0;i<N/2;i++)  cout<<N-2*i-(N&1)<<' ';

}