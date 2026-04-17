#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int ans[2001][2001]{};
	priority_queue<pair<int, int>> Q;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		if (a)	Q.emplace(a, i);
	}

	while (!Q.empty()) {
		auto [t, n] = Q.top();
		Q.pop();
		vector<pair<int, int>> temp;
		while (!Q.empty() && t) {
			auto [a, b] = Q.top();
			Q.pop();
			ans[n][b] = ans[b][n] = 1;
			temp.emplace_back(--a, b);
			t--;
		}
		if (t) { cout << -1; return 0; }
		for (auto [a, b] : temp)	if (a)	Q.emplace(a, b);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)	cout << ans[i][j] << ' ';
		cout << '\n';
	}

}