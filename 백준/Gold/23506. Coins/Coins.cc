#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	vector<pair<int, int>> arr(N);
	for (auto& [a, b] : arr)	cin >> a >> b;
	sort(arr.begin(), arr.end());
	ll ans = 0, s = 1;
	for (auto& [a, b] : arr) {
		ans += abs(s - a);
		s++;
	}
	sort(arr.begin(), arr.end(), [](auto a, auto b) -> bool {
		if (a.second == b.second)	return a.first < b.first;
		return a.second < b.second;
	});
	s = 1;
	for (auto& [a, b] : arr) {
		ans += abs(s - b);
		s++;
	}
	cout << ans;

}