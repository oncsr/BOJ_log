#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m;
    cin>>n>>m;
    int arr[1000]{};
    vector<int> V;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<i;j++){
            if(arr[i] + arr[j] > m) continue;
            V.push_back(-(arr[i]+arr[j]));
        }
        V.push_back(-arr[i]);
    }
    V.push_back(0);
    sort(V.begin(), V.end());
    int ans = 0;
    for(int i=0;i<V.size();i++){
        int pos = lower_bound(V.begin(), V.end(), abs(V[i])-m)-V.begin();
        if(pos == V.size()) continue;
        ans = max(ans, abs(V[pos]) + abs(V[i]));
    }
    cout<<ans;

}