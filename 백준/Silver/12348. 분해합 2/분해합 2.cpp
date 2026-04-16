#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N;
	cin >> N;
	for (ll i = max(1LL, N - 200); i <= N; i++) {
		ll a = i;
		for (char j : to_string(i))	 a += j - '0';
		if (a == N)	return cout << i, 0;
	}
	cout << 0;

}