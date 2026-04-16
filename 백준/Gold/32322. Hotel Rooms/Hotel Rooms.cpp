#include <bits/stdc++.h>
using namespace std;

int seg[1048577]{};

int init(int s, int e, int n){
    if(s == e)  return seg[n] = 1;
    int m=(s+e)>>1;
    return seg[n] = init(s,m,n*2) + init(m+1,e,n*2+1);
}

void upt(int s, int e, int i, int n){
    if(s == e)  {seg[n] = 0;return;}
    int m=(s+e)>>1;
    if(i <= m)  upt(s,m,i,n*2);
    else    upt(m+1,e,i,n*2+1);
    seg[n] = seg[n*2] + seg[n*2+1];
}

int find(int s, int e, int l, int r, int n){
    if(l>r || l>e || r<s)   return 0;
    if(l <= s && e <= r)    return seg[n];
    int m=(s+e)>>1;
    return find(s,m,l,r,n*2) + find(m+1,e,l,r,n*2+1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N, T;
    cin>>N>>T;
    init(1,N,1);
    for(;T--;){
        char o;
        int a,b;
        cin>>o>>a;
        if(o == 'R')    upt(1,N,a,1);
        else{
            cin>>b;
            cout<<find(1,N,a,b,1)<<'\n';
        }
    }
    
}