#include <bits/stdc++.h>
using namespace std;

int seg[1048577]{}, arr[500001]{};

void prop(int s, int e, int n){
    if(seg[n]){
        int v = seg[n];
        if(s == e)  arr[s] ^= v;
        else{
            seg[n*2] ^= v;
            seg[n*2+1] ^= v;
        }
        seg[n] = 0;
    }
}

void upt(int s, int e, int l, int r, int v, int n){
    prop(s,e,n);
    if(l>r || l>e || r<s)   return;
    if(l<=s && e<=r){
        if(s == e)  arr[s] ^= v;
        else{
            seg[n*2] ^= v;
            seg[n*2+1] ^= v;
        }
        return;
    }
    int m=(s+e)>>1;
    upt(s,m,l,r,v,n*2); upt(m+1,e,l,r,v,n*2+1);
}

int find(int s, int e, int i, int n){
    prop(s,e,n);
    if(s==e)    return arr[s];
    int m=(s+e)>>1;
    if(i <= m)  return find(s,m,i,n*2);
    return find(m+1,e,i,n*2+1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin>>n;
    for(int i=1;i<=n;i++)    cin>>arr[i];
    for(cin>>m;m--;){
        int o,a,b,c;
        cin>>o>>a;
        if(o == 2)  cout<<find(1,n,a+1,1)<<'\n';
        else{
            cin>>b>>c;
            upt(1,n,a+1,b+1,c,1);
        }
    }
    
}