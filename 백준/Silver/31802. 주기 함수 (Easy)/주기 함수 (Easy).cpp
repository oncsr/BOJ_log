#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int p;
	cin>>p;
	ll F[100000]{};
	for(int i=0;i<p;i++)	cin>>F[i], F[i] += F[i-1];

	ll a,b;
	cin>>a>>b;
	ll res = 0;
	ll s;
	if(a < 0){
		if((-a)%p)	s = (-a)/p + 1;
		else 	s = (-a)/p;
	}
	else	s = -(a/p);
	a += s*p;
	b += s*p;

	if(b <= p)	res += F[b?b-1:0] - F[a?a-1:0];
	else{
		res += F[p-1] - F[a?a-1:0];
		res += (b/p - 1) * F[p-1];
		b %= p;
		res += F[b?b-1:0];
	}
	cout<<res;

}