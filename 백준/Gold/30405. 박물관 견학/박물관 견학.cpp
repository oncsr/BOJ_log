#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll N, M;
    cin>>N>>M;
    vector<ll> V;
    for(int i=0;i<N;i++){
        int k, a;
        cin>>k>>a;
        V.push_back(a);
        for(int j=1;j<k;j++){
            cin>>a;
        }
        V.push_back(a);
    }
    sort(V.begin(), V.end());
    vector<ll> arr(V.size());
    arr[0] = V[0];
    for(int i=1;i<V.size();i++) arr[i] = V[i] + arr[i-1];
    
    ll val = 1e18, ans = 0, i;
    int pos = 0;
    for(i=V[0];i<=V.back();i++){
        while(pos < V.size() && V[pos] <= i)    pos++;
        if(pos == V.size()){
            ll now = 2*N*i - arr.back();
            if(now < val)   val = now, ans = i;
            break;
        }
        ll now = pos * i - arr[pos-1] + arr[V.size()-1] - arr[pos-1] - (2*N-pos)*i;
        if(now < val)   val = now, ans = i;
    }
    
    cout<<ans;

}