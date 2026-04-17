#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll, ll>> arr;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int TC;
    for(cin>>TC;TC--;){

        int N, k;
        cin>>N>>k;
        arr = vector<pair<ll, ll>>(N);
        ll sum = 0;
        for(int i=0;i<N;i++){
            ll a;
            cin>>a;
            sum += a;
            arr[i].first = a;
        }
        for(int i=0;i<N;i++)    cin>>arr[i].second;
        sort(arr.begin(), arr.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
            return a.second - a.first > b.second - b.first;
        });
        ll ans = 0;
        for(int i=0;i<N;i++){
            sum += arr[i].second - arr[i].first;
            if(abs(N-2*(i+1)) <= k)    ans = max(ans, sum);
        }
        cout<<ans<<'\n';

    }


}