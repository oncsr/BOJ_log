#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll x,y,r;
	for(cin>>x>>y>>r;x;cin>>x>>y>>r){
		ll ans = 0, p = 0;
		for(ll i=r-1;i>=0;i--){
			ll xs = r*r - i*i;
			ll x = ceill(sqrtl(xs));
			ans += (x-p)*(i+1)*4;
			p = x;
		}
		cout<<ans<<'\n';

	}

}