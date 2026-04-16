#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n,a[200001][2]{};
ll d[200001][3]{};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i][0];
    for(int i=1;i<=n;i++)   cin>>a[i][1];

    d[1][0] = a[1][0];
    d[1][1] = -1e18;
    d[1][2] = a[1][0]+a[1][1];

    for(int i=2;i<=n;i++){
        d[i][0] = max(d[i-1][0], d[i-1][2]) + a[i][0];
        d[i][1] = max(d[i-1][1], d[i-1][2]) + a[i][1];
        d[i][2] = max({d[i-1][0], d[i-1][1], d[i-1][2]}) + a[i][0] + a[i][1];
    }
    cout<<max(d[n][1], d[n][2]);

}