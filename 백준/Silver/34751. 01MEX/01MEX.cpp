#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bitset<500000> a;
ll N, ans = 0;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=0,b;i<N;i++) cin>>b, a[i] = b;
    ll cnt = N*(N+1)/2;
    for(int i=0;i<N;i++) {
        int j=i;
        while(j<N && a[i] == a[j]) j++;
        ll len = j-i, c = len*(len+1)/2;
        cnt -= c;
        if(!a[i]) ans += c;
        i = j-1;
    }
    cout<<ans + cnt*2;

}