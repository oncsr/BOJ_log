#include<bits/stdc++.h>
using namespace std;int s[100001][2];vector<int>V[100001];void d(int n,int P){s[n][1]=P,s[n][0]=1;for (int i:V[n])if(i!=P){d(i,n);s[n][0]+=s[i][0];}}
main(){cin.tie(0)->sync_with_stdio(0);int N,R,Q,a,b;cin>>N>>R>>Q;for (int i=1;i<N;i++){cin>>a>>b;V[a].push_back(b);V[b].push_back(a);}d(R,0);for(;Q--;){cin>>a;cout<<s[a][0] << '\n'; } }