#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	vector<vector<int>> V(N + 1);
	vector<int> C(N + 1);

	for (int i = 2, a; i <= N; i++) {
		cin >> a;
		V[a].push_back(i);
	}

	stack<pair<int, int>> S;
	S.emplace(1, 0);
	while (!S.empty()) {
		auto [n, d] = S.top();	S.pop();
		C[d]++;
		for (int i : V[n]) S.emplace(i, d + 1);
	}

	int ans = 0;
	for (int i = 2; i <= N; i++) {
		int res = 0;
		for (int j = 0; j < N; j += i) res += C[j];
		ans = max(ans, res);
	}
	cout << ans;

}