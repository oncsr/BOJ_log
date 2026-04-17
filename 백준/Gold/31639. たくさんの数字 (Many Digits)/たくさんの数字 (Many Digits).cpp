#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	vector<int> A(N);
	for (int& i : A)	cin >> i;
	sort(A.begin(), A.end());

	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ll x;
		cin >> x;
		ll prev = 0;
		for (ll g = 10, l = 1; g <= 10'000'000'000LL; g *= 10, l++) {
			if (x >= g)	continue;
			ll p = lower_bound(A.begin(), A.end(), g - x) - A.begin();
			ans += l * (p - prev);
			prev = p;
			if (p == N)	break;
		}
	}
	cout << ans;

}