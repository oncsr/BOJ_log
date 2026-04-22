#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int root[100000]{};
int find(int x) {
	if (x == root[x])	return x;
	return root[x] = find(root[x]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)	root[i] = i;
	pair<ll, int> X[100000]{};
	pair<ll, int> Y[100000]{};
	pair<ll, int> Z[100000]{};
	for (int i = 0; i < N; i++) {
		ll x, y, z;
		cin >> x >> y >> z;
		X[i] = { x,i };
		Y[i] = { y,i };
		Z[i] = { z,i };
	}
	vector<pair<ll, pair<int, int>>> E;
	sort(X, X + N);
	for (int i = 0; i < N - 1; i++) {
		E.push_back({ abs(X[i].first - X[i + 1].first), {X[i].second, X[i + 1].second} });
	}
	sort(Y, Y + N);
	for (int i = 0; i < N - 1; i++) {
		E.push_back({ abs(Y[i].first - Y[i + 1].first), {Y[i].second, Y[i + 1].second} });
	}
	sort(Z, Z + N);
	for (int i = 0; i < N - 1; i++) {
		E.push_back({ abs(Z[i].first - Z[i + 1].first), {Z[i].second, Z[i + 1].second} });
	}
	sort(E.begin(), E.end());
	ll ans = 0;
	for (auto e : E) {
		ll cost = e.first;
		int a = e.second.first, b = e.second.second;
		int x = find(a), y = find(b);
		if (x == y)	continue;
		root[x] = y;
		ans += cost;
	}
	cout << ans;
}