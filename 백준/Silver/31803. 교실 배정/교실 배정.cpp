#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin>>N;
	ll res = 1, p = N/2;
	while(N >= 2){
		res *= N*(N-1)/2;
		while(p > 0 && res % p == 0)	res /= (p--);
		N -= 2;
	}
	cout<<res;

}