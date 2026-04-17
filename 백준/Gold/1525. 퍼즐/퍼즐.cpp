#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	vector<int> dest = { 1,2,3,4,5,6,7,8,0 };
	set<vector<int>> vis;
	vector<int> start;
	int zero = 0;
	for (int i = 0; i < 9; i++) {
		int a;
		cin >> a;
		start.push_back(a);
		if (!a)	zero = i;
	}
	vis.insert(start);

	queue<tuple<vector<int>, int, int>> Q;
	Q.emplace(start, zero, 0);

	auto work = [&](vector<int>& now, int x, int y, int t) -> void {
		swap(now[x], now[y]);
		if (!vis.count(now))	vis.insert(now), Q.emplace(now, y, t + 1);
		swap(now[x], now[y]);
	};
	while (!Q.empty()) {
		auto [now, id, t] = Q.front();
		Q.pop();
		if (now == dest) { cout << t; return 0; }
		// left
		if (id % 3)	work(now, id, id - 1, t);
		// right
		if (id % 3 != 2)	work(now, id, id + 1, t);
		// up
		if (id / 3)	work(now, id, id - 3, t);
		// down
		if (id / 3 != 2)	work(now, id, id + 3, t);
	}
	cout << -1;

}