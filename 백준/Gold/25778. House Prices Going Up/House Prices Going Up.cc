#include <iostream>
using namespace std;
using ll=long long;
char o;ll T[500001]{},S[1048577]{},N,M,a,b;
void I(ll s,ll e,ll n){if(s==e){S[n]=T[s];return;}I(s,(s+e)/2,n*2);I((s+e)/2+1,e,n*2+1);S[n]=S[n*2]+S[n*2+1];}
void U(ll s,ll e,ll x,ll v,ll n){if(s==e){S[n]+=v;return;}ll m=(s+e)/2;if(x<=m)U(s,m,x,v,n*2);else U(m+1,e,x,v,n*2+1);S[n]=S[n*2]+S[n*2+1];}
ll F(ll s,ll e,ll l,ll r,ll n){if(l>e||r<s)return 0;if(l<=s&&e<=r)return S[n];return F(s,(s+e)/2,l,r,n*2)+F((s+e)/2+1,e,l,r,n*2+1);}
main(){cin.tie(0)->sync_with_stdio(0);cin>>N;for(int i=1;i<=N;i++)cin>>T[i];I(1,N,1);for(cin>>M;M--;){cin>>o>>a>>b;if(o=='U')U(1,N,a,b,1);else cout<<F(1,N,a,b,1)<<'\n';}}