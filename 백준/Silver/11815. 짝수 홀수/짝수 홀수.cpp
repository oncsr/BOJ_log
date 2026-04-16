#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int T;
	for (cin >> T; T--;) {
		ll N;
		cin >> N;
		long double s = sqrtl(N);
		if (ll(s) * ll(s) == N)	cout << "1 ";
		else	cout << "0 ";
	}

}