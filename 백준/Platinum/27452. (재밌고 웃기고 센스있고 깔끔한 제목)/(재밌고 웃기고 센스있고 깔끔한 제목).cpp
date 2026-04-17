#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> len = { 0,2,2 };

char sol(ll n, ll k) {
	if (k == 1)	return '(';
	if (n <= 2)	return ')';
	if (k == len[n])	return ')';
	if (k <= 1 + len[n - 2])	return sol(n - 2, k - 1);
	return sol(n - 1, k - len[n - 2] - 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	for (int i = 3; len.back() <= 4e18; i++)	len.push_back(len[i - 2] + len[i - 1] + 2);
	ll T;
	for (cin >> T; T--;) {
		ll n, k;
		cin >> n >> k;
		if (n <= 85) {
			if (k > len[n]) { cout << "0\n"; continue; }
		}
		else {
			ll v = min((n - 86) / 2, k - 1);
			n -= v * 2, k -= v;
			if (k == 1) { cout << "(\n"; continue; }
		}
		cout << sol(n, k) << '\n';
	}

}