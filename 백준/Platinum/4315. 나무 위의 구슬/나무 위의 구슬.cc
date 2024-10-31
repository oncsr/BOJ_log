#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	for (cin >> N; N; cin >> N) {
		vector<vector<int>> V(N + 1);
		vector<ll> A(N + 1);
		vector<bool> B(N + 1);
		for (int i = 1, n, v, d; i <= N; i++) {
			cin >> n >> v >> d;
			A[n] = v;
			for (int c; d--; V[n].push_back(c))	cin >> c, B[c] = 1;
		}

		vector<ll> sub(N + 1), sum(N + 1);
		ll ans = 0;
		function<void(int)> dfs = [&](int n) -> void {
			sub[n] = 1;
			sum[n] = A[n];
			for (int i : V[n]) {
				dfs(i);
				ans += abs(sum[i] - sub[i]);
				sum[n] += sum[i];
				sub[n] += sub[i];
			}
		};

		int root = 1;
		while (B[root])	root++;
		dfs(root);

		cout << ans << '\n';

	}
}