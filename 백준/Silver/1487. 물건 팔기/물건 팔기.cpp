#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	vector<pair<int, int>> A(N);
	for (auto& [a, b] : A) cin >> a >> b;
	int mx = 0, ans = 0;
	for (auto [pr, de] : A) {
		int res = 0;
		for (auto [a, b] : A) if (a >= pr) res += max(0, pr - b);
		if (res > mx || (res == mx && pr < ans)) mx = res, ans = pr;
	}
	cout << ans;

}