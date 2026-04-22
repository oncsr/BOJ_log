#include <bits/stdc++.h>
using namespace std;

vector<int> root;
int find(int x) {
	if (x == root[x])	return x;
	return root[x] = find(root[x]);
}

void init(int n) {
	root = vector<int>(n + 1);
	for (int i = 1; i <= n; i++)	root[i] = i;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m, k;
	for (cin >> n >> m >> k; n; cin >> n >> m >> k) {
		vector<pair<int, pair<int, int>>> E;
		for (; m--;) {
			char a;
			int b, c;
			cin >> a >> b >> c;
			E.push_back({ a == 'B',{b,c} });
		}
		init(n);
		int L = 0, R = 0;
		sort(E.begin(), E.end());
		for (auto e : E) {
			int x = find(e.second.first), y = find(e.second.second);
			if (x == y)	continue;
			root[x] = y;
			L += e.first;
		}
		init(n);
		sort(E.begin(), E.end(), greater<>());
		for (auto e : E) {
			int x = find(e.second.first), y = find(e.second.second);
			if (x == y)	continue;
			root[x] = y;
			R += e.first;
		}
		cout << (int)(L <= k && k <= R) << '\n';
	}
}