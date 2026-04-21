#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll col[100001]{}, row[100001]{}, n, ans = 0;
    ii arr[100000]{};
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        col[a]++, row[b]++;
        arr[i] = {a,b};
    }
    for(int i=0;i<n;i++)    ans += (col[arr[i].first]-1) * (row[arr[i].second]-1);
    cout<<ans;

}