#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll F(ll n, ll k){
	ll res = 0, v = 1;
	while(n >= v){
		if(k == 0 && n < v*10)	break;
		if(k)	res += (n/(v*10)) * v;
		else 	res += (n/(v*10) - 1) * v;
		res += min(v, max(0LL, n%(v*10) - v*k + 1));
		v *= 10;
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll n;
	cin>>n;

	cout<<F(n,0)+F(n,6)+F(n,8)*2+F(n,9)<<'\n';

}