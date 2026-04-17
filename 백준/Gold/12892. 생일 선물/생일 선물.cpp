#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ll N, D;
	cin >> N >> D;
	vector<pair<ll, ll>> A(N);
	for (auto& [i, j] : A)	cin >> i >> j;
	sort(A.begin(), A.end());

	ll ans = A[0].second, s = 0, val = A[0].second;
	for (int i = 1; i < N; i++) {
		auto [p, v] = A[i];
		while (p - A[s].first >= D) {
			val -= A[s].second;
			s++;
		}
		val += v;
		ans = max(ans, val);
	}
	cout << ans;

}