#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int N, M, K;
vector<vector<int>> I(100001);
int A[1000001]{};
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M>>K;
    for(int i=0;i<N;i++) cin>>A[i], I[A[i]].push_back(i);
    
    ll ans = 0;
    for(int i=0;i<N;i++){
        int a = A[i] ^ K;
        if(a > 100000) continue;
        ans += upper_bound(I[a].begin(), I[a].end(),i+M) - upper_bound(I[a].begin(), I[a].end(),i);
    }
    cout<<ans;
    
}
