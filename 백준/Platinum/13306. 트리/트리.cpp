#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, Q;
	cin >> N >> Q;
	Q += N - 1;
	vector<tuple<int, int, int>> query;
	int par[200001]{}, root[200001] = { 0,1 };

	function<int(int)> find = [&](int x) -> int {
		if (x == root[x])	return x;
		return root[x] = find(root[x]);
	};

	for (int i = 2; i <= N; i++) {
		int a;
		cin >> a;
		par[i] = a, root[i] = i;
	}

	for (; Q--;) {
		int a, b, c = 0;
		cin >> a >> b;
		if (a)	cin >> c;
		query.emplace_back(a, b, c);
	}

	reverse(query.begin(), query.end());
	stack<string> ans;
	for (auto& [o, a, b] : query) {
		if (!o) {
			int x = find(a), y = find(par[a]);
			root[x] = y;
		}
		else {
			ans.push(find(a) == find(b) ? "YES\n" : "NO\n");
		}
	}
	while (!ans.empty())	cout << ans.top(), ans.pop();

}