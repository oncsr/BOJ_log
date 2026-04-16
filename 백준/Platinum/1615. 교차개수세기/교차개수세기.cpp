#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<pair<int,int>> v;
int seg[4096]{};

void upt(int s, int e, int i, int n) {
    if(s==e) {
        seg[n]++;
        return;
    }
    int m=(s+e)>>1;
    if(i<=m) upt(s,m,i,n*2);
    else upt(m+1,e,i,n*2+1);
    seg[n] = seg[n*2] + seg[n*2+1];
}

int find(int s, int e, int l, int r, int n) {
    if(l>r || l>e || r<s) return 0;
    if(l<=s && e<=r) return seg[n];
    int m=(s+e)>>1;
    return find(s,m,l,r,n*2) + find(m+1,e,l,r,n*2+1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M;
    v.resize(M);
    for(auto &[a,b]:v) cin>>a>>b;
    sort(v.begin(), v.end());

    long long ans = 0;
    for(auto [a,b]:v) {
        ans += find(1,N,b+1,N,1);
        upt(1,N,b,1);
    }
    cout<<ans;

}