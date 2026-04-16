#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, D, K, C;
    cin>>N>>D>>K>>C;
    int arr[30000]{};
    for(int i=0;i<N;i++)    cin>>arr[i];
    int s=0, e=K-1;
    int cnt[3001]{};
    int cur = 1;
    cnt[C]++;
    for(int i=s;i<=e;i++)   if(!cnt[arr[i]]++)  cur++;

    int ans = cur;
    while(s < N){
        if(!--cnt[arr[s]])  cur--;
        s++,e++;
        if(!cnt[arr[e%N]]++)  cur++;
        ans = max(ans, cur);
    }
    cout<<ans;

}