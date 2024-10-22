#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	int r[100001]{};
	iota(r, r + N + 1, 0);
	function<int(int)> F = [&](int x) -> int {
		if (x == r[x])	return x;
		return r[x] = F(r[x]);
	};

	vector<tuple<ld, int, int>> E;
	ld p;
	for (int a, b; M--; E.emplace_back(p, a, b))	cin >> a >> b >> p;
	sort(E.begin(), E.end(), greater<>());

	int Q;
	cin >> Q;
	vector<pair<ld, int>> q;
	vector<int> ans(Q);
	for (int i = 0; Q--; q.emplace_back(p, i++))	cin >> p;
	sort(q.begin(), q.end(), greater<>());

	int id = 0, s = N;
	for (auto& [g, i] : q) {
		while (id < E.size()) {
			auto& [h, a, b] = E[id];
			if (h >= g) {
				id++;
				int x = F(a), y = F(b);
				if (x == y)	continue;
				s--;
				r[x] = y;
			}
			else	break;
		}
		ans[i] = s;
	}
	for (int& i : ans)	cout << i << '\n';

}