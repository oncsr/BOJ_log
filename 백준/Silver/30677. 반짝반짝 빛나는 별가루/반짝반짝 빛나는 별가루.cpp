#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, K, C, R;
    cin>>N>>K>>C>>R;

    ll base[100001]{}, s[100001]{}, p[100001]{}, skill[100001]{};
    for(int i=1;i<=K;i++)   cin>>base[i];
    for(int i=1;i<=K;i++)   cin>>s[i];
    for(int i=1;i<=K;i++)   cin>>p[i];
    ll ans = 0, tired = 0, combo = 0;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        if(!a)  {combo = 0, tired = max(0LL, tired-R);  continue;}
        ll up = base[a] * (100 + combo * C) * (100 + skill[a] * s[a]);
        ans += up/10000;
        skill[a]++;
        combo++;
        tired += p[a];
        if(tired > 100){cout<<-1;return 0;}
    }
    cout<<ans;
}