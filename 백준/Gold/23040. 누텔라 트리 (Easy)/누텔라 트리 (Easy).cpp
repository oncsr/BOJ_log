#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int r[100001]{},c[100001]{};
int F(int x){return x==r[x]?x:r[x]=F(r[x]);}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin>>n;
    iota(r,r+n+1,0);    fill(c,c+n+1,1);
    vector<vector<int>> V(n+1);
    for(int i=1,a,b;i<n;i++){
        cin>>a>>b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        if(s[i-1] == 'B')    continue;
        for(int j:V[i]){
            if(s[j-1] == 'B')   continue;
            int x=F(i),y=F(j);
            if(x==y)    continue;
            c[y]+=c[x];
            r[x]=y;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(s[i-1] == 'R')   continue;
        for(int j:V[i]){
            if(s[j-1] == 'B')   continue;
            ans += c[F(j)];
        }
    }
    cout<<ans;

}