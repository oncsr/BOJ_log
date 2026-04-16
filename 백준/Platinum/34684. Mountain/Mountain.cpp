#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> arr;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	arr.resize(N);
	for (auto& [x, y] : arr) cin >> x >> y;

	sort(arr.begin(), arr.end(), [](auto a, auto b) -> bool {
		auto [ax, ay] = a;
		auto [bx, by] = b;
		if (ay - ax == by - bx) return ax > bx;
		return ay - ax > by - bx;
	});

	vector<int> v;
	for (auto [x, y] : arr) {
		int idx = lower_bound(v.begin(), v.end(), x + y) - v.begin();
		if (idx == v.size()) v.push_back(x + y);
		else v[idx] = x + y;
	}
	cout << v.size();

}