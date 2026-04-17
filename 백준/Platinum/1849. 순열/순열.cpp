#include <bits/stdc++.h>
using namespace std;

int seg[262145]{}, N;

void upt(int s, int e, int i, int n){
    if(s == e){seg[n]++;return;}
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

    cin>>N;
    int ans[100001]{};
    for(int i=1;i<=N;i++){
        int a;
        cin>>a;
        a++;
        int s = 1, e = N, m = (s+e)>>1;
        while(s<e){
            int g = m - find(1,N,1,m,1);
            if(g < a)   s = m+1;
            else    e = m;
            m = (s+e)>>1;
        }
        ans[m] = i;
        upt(1,N,m,1);
    }
    for(int i=1;i<=N;i++)   cout<<ans[i]<<'\n';

}