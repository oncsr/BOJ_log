#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int r[10001]{}, ans = 1e9, A[10001]{};
	function<int(int)> f = [&](int x) -> int { return x == r[x] ? x : r[x] = f(r[x]); };
	int N, P;
	cin >> N >> P;
	iota(r, r + N + 1, 0);
	vector<tuple<int, int, int>> E(P);
	for (int i = 1; i <= N; i++) cin >> A[i], ans = min(ans, A[i]);
	for (int i = 0, a, b, c; i < P; i++) {
		cin >> a >> b >> c;
		E[i] = { c * 2 + A[a] + A[b], a, b };
	}

	sort(E.begin(), E.end());
	for (auto [c, a, b] : E) {
		int x = f(a), y = f(b);
		if (x == y) continue;
		ans += c;
		r[x] = y;
	}
	cout << ans;

}