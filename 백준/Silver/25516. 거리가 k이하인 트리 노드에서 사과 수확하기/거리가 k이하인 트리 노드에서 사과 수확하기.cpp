#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K;
	cin >> N >> K;
	vector<vector<int>> V(N);
	vector<int> A(N);
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
	}
	for (int &i : A)	cin >> i;

	int ans = 0;
	function<void(int, int)> dfs = [&](int n, int d) -> void {
		ans += A[n];
		if (d == K)	return;
		for (int i : V[n])	dfs(i, d + 1);
	};
	dfs(0, 0);

	cout << ans;

}