#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll S(ll n){
	ll res = 0, v = 1;
	while(n >= v){
		res += (n/(v*2)) * v + max(0LL, n%(v*2) - v + 1);
		v <<= 1;
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ll A, B;
	cin>>A>>B;
	cout<<S(B) - S(A-1);
}