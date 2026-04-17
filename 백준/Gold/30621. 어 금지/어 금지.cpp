#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;
using pl = pair<ll, ll>;

ll seg[262145]{};

void upt(int s, int e, int i, ll v, int n){
    if(s==e){
        seg[n] = v;
        return;
    }
    int m=(s+e)>>1;
    if(i <= m)  upt(s,m,i,v,n*2);
    else    upt(m+1,e,i,v,n*2+1);
    seg[n] = max(seg[n*2], seg[n*2+1]);
}

ll find(int s, int e, int l, int r, int n){
    if(l > r || l > e || r < s) return 0;
    if(l <= s && e <= r)    return seg[n];
    int m=(s+e)>>1;
    return max(find(s,m,l,r,n*2), find(m+1,e,l,r,n*2+1));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N;
    ll dp[100001]{};

    cin>>N;
    ll T[100001]{}, B[100001]{}, C[100001]{};
    for(int i=1;i<=N;i++)   cin>>T[i];
    for(int i=1;i<=N;i++)   cin>>B[i];
    for(int i=1;i<=N;i++)   cin>>C[i];

    dp[1] = C[1];
    upt(1,N,1,C[1], 1);
    ll mx = dp[1];
    for(int i=2;i<=N;i++){
        int pos = lower_bound(T, T+i, T[i] - B[i]) - T;
        pos--;
        dp[i] = C[i];
        dp[i] += find(1,N,1,pos,1);
        mx = max(mx, dp[i]);
        upt(1,N,i,dp[i],1);
    }

    cout<<mx;

}