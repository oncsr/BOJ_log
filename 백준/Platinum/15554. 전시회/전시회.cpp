#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin>>N;
    vector<pair<ll, ll>> arr(N);
    for(auto &[a,b] : arr)  cin>>a>>b;
    sort(arr.begin(), arr.end());
    
    vector<ll> p1(N);
    p1[0] = arr[0].second;
    for(int i=1;i<N;i++)    p1[i] += p1[i-1] + arr[i-1].first + arr[i].second - arr[i].first;
    vector<ll> mxp1(N);
    mxp1[N-1] = p1[N-1];
    for(int i=N-2;i>=0;i--)  mxp1[i] = max(mxp1[i+1], p1[i]);
    vector<ll> p2(N);
    for(int i=1;i<N;i++)    p2[i] += p2[i-1] + arr[i].first - arr[i-1].first - arr[i-1].second;

    ll ans = arr[0].second;
    for(int i=0;i<N;i++)    ans = max(ans, p2[i] + mxp1[i]);
    cout<<ans;

}