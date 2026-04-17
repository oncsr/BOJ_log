#include <bits/stdc++.h>
using namespace std;

int root[100001]{}, cnt[100001]{};

int find(int x) {
	if (x == root[x])	return x;
	return root[x] = find(root[x]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)	cin >> cnt[i], root[i] = i;

	for (; M--;) {
		int o, p, q;
		cin >> o >> p >> q;
		int x = find(p), y = find(q);
		if (x == y)	continue;
		root[x] = y;
		if (o == 1) {
			cnt[y] += cnt[x];
		}
		else {
			cnt[y] = abs(cnt[y] - cnt[x]);
		}

	}
	int vis[100001]{};
	priority_queue<int, vector<int>, greater<>> Q;
	for (int i = 1; i <= N; i++) {
		int x = find(i);
		if (vis[x])	continue;
		if (cnt[x])	Q.emplace(cnt[x]);
		vis[x]++;
	}

	cout << Q.size() << '\n';
	for (; !Q.empty(); cout << Q.top() << ' ', Q.pop());
}