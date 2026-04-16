#include <bits/stdc++.h>
using namespace std;

int seg[262145]{};
void upt(int s, int e, int i, int n){
    if(s==e){seg[n]++;return;}
    int m=(s+e)>>1;
    if(i<=m)    upt(s,m,i,n*2);
    else    upt(m+1,e,i,n*2+1);
    seg[n]=seg[n*2]+seg[n*2+1];
}

int find(int s, int e, int l, int r, int n){
    if(l>r || l>e || r<s)   return 0;
    if(l<=s && e<=r)    return seg[n];
    int m=(s+e)>>1;
    return find(s,m,l,r,n*2)+find(m+1,e,l,r,n*2+1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N,c=0,M;
    cin>>N;
    vector<pair<int, int>> arr(N);
    for(auto &[a,b]:arr)    cin>>a, b=++c;
    cin>>M;
    c=0;
    vector<tuple<int,int,int,int>> que(M);
    for(auto &[x,y,z,i]:que)  cin>>y>>z>>x,i=c++;
    sort(arr.begin(), arr.end(), greater<>());
    sort(que.begin(), que.end(), greater<>());

    int id = 0;
    vector<int> ans(M);
    for(auto &[z,x,y,i]:que){
        while(id<N && arr[id].first>z)  upt(1,N,arr[id++].second,1);
        ans[i]=find(1,N,x,y,1);
    }
    for(int &i:ans) cout<<i<<'\n';

}