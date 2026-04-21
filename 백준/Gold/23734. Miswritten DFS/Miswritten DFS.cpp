#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

ll sub[100001]{}, N, K;
ii tree[100001]{};

void dfs(int n){
    sub[n] = 1;
    int L = tree[n].first, R = tree[n].second;
    
    if(L){
        dfs(L);
        sub[n] += 2 * sub[L];
        if(sub[n] > 1e18)   sub[n] = 1e18+1;
    }

    if(R){
        dfs(R);
        sub[n] += sub[R];
        if(sub[n] > 1e18)   sub[n] = 1e18+1;
    }
}

ll solve(int n, ll k){
    int L = tree[n].first, R = tree[n].second;
    if(k == K)  return n;
    
    if(L){
        if(K <= k+sub[L]*2){
            if(K > k+sub[L]) K -= sub[L];
            return solve(L, k+1);
        }
        k += sub[L]*2;
        if(R)   return solve(R, k+1);
    }
    return solve(R, k+1);

}


int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>K;
    for(int i=1;i<=N;i++)   cin>>tree[i].first>>tree[i].second;

    dfs(1);
    

    cout<<solve(1, 1);

}