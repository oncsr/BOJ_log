#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ld v, m, xs, ys, xt, yt;
	cin >> v >> m >> xs >> ys >> xt >> yt;
	vector<pair<ld, ld>> A = { make_pair(xs,ys) };
	for (ld x, y; cin >> x >> y; A.emplace_back(x, y));
	A.emplace_back(xt, yt);

	auto dist = [](pair<ld, ld> a, pair<ld, ld> b) -> ld {
		return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
	};

	vector<vector<int>> V(A.size());
	for (int i = 0; i < A.size(); i++) {
		for (int j = i + 1; j < A.size(); j++) {
			if (dist(A[i], A[j]) >= m * m * v * v * 3600)	continue;
			V[i].push_back(j);
			V[j].push_back(i);
		}
	}

	queue<pair<int, int>> Q;
	Q.emplace(0, 0);
	vector<int> vis(A.size());
	vis[0]++;
	while (!Q.empty()) {
		auto [n, t] = Q.front();	Q.pop();
		if (n == A.size() - 1)	return cout << "Yes, visiting " << t - 1 << " other holes.", 0;
		for (int i : V[n]) {
			if (vis[i])	continue;
			vis[i]++;
			Q.emplace(i, t + 1);
		}
	}
	cout << "No.";

}