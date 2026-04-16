#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin>>N;
	vector<pair<ll,ll>> v(N);
	for(auto &[x,y]:v) cin>>x>>y;
	auto f = [](pair<ll,ll> a, pair<ll,ll> b) -> ll {
		return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
	};
	ll ans = 0;
	for(int i=0;i<N;i++) for(int j=i+1;j<N;j++) for(int k=j+1;k<N;k++) {
        ll a = f(v[i], v[j]);
        ll b = f(v[j], v[k]);
        ll c = f(v[k], v[i]);
        ll s = a+b+c, x = max({a,b,c});
        if(s-x == x) ans++;
	}
	cout<<ans;

}