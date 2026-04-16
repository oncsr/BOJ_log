#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, ans = 0;
	cin >> N;
	vector<pair<ll, ll>> arr(N);
	for (auto& [a, b] : arr)	cin >> a >> b;
	sort(arr.begin(), arr.end(), [](auto a, auto b) -> bool {
		auto [ti, ai] = a;
		auto [tj, aj] = b;
		return ai * ti + aj * (2 * ti + tj + 1) < aj * tj + ai * (2 * tj + ti + 1);
	});

	ll h = 0, p = 0;
	for (auto& [t, a] : arr) {
		ans += a * (h + t + (p++));
		h += 2 * t;
	}
	cout << ans;

}