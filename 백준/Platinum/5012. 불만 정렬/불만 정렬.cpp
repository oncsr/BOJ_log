#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll seg[262145][2]{};

void upt(int a, int s, int e, int i, int v, int n){
    if(s == e){seg[n][a] += v;return;}
    int m=s+e>>1;
    if(i<=m)    upt(a,s,m,i,v,n*2);
    else    upt(a,m+1,e,i,v,n*2+1);
    seg[n][a] = seg[n*2][a] + seg[n*2+1][a];
}

ll find(int a, int s, int e, int l, int r, int n){
    if(l>r || l>e || r<s)   return 0;
    if(l<=s && e<=r)    return seg[n][a];
    int m=s+e>>1;
    return find(a,s,m,l,r,n*2) + find(a,m+1,e,l,r,n*2+1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N, c= 0;
    cin>>N;
    vector<pair<int,int>> A(N);
    for(auto &[a,b]:A)  cin>>b, a=++c;
    
    sort(A.begin(), A.end(), [](auto a, auto b) -> bool{if(a.second == b.second)return a.first < b.first; return a.second < b.second;});
    for(auto &[a,b]:A)  upt(1,1,N,a,1,1);
    ll ans = 0;
    for(auto &[a,b]:A){
        ans += find(0,1,N,a+1,N,1) * find(1,1,N,1,a-1,1);
        upt(0,1,N,a,1,1);
        upt(1,1,N,a,-1,1);
    }
    cout<<ans;
    
}