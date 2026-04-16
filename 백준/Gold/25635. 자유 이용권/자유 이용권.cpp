#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, mx = 0, s = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		ll a;
		cin >> a;
		s += a;
		mx = max(mx, a);
	}
	cout << min(s, (s - mx) * 2 + 1);

}