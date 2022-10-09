#include<iostream>
#include<queue>
using namespace std;
using ll=long long;
char o;ll N,M,Q,T,a,b;vector<ll>S(262145);
void U(ll s,ll e,ll x,ll v,ll n){if(s==e){S[n]+=v;return;}ll m=(s+e)/2;if(x<=m)U(s,m,x,v,n*2);else U(m+1,e,x,v,n*2+1);S[n]=S[n*2]+S[n*2+1];}
ll F(ll s,ll e,ll l,ll r,ll n){if(l>e||r<s)return 0;if(l<=s&&e<=r)return S[n];return F(s,(s+e)/2,l,r,n*2)+F((s+e)/2+1,e,l,r,n*2+1);}
int main(){cin.tie(0)->sync_with_stdio(0);for(cin>>T;T--;){S=vector<ll>(262145);cin>>N>>M>>Q;for(int p=M+Q;p--;){cin>>o>>a>>b;if(o=='P')U(1,N,a,b,1);else cout<<F(1,N,a,b,1)<<'\n';}}}