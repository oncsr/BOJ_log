#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	int dir = 0;
	ii now = { 0,0 };
	vector<ii> vis = { now };
	int left = 0, right = 0;
	for (cin >> n; n--;) {
		char a;
		cin >> a;
		if (a == 'L')	dir--;
		else if (a == 'R')	dir++;
		else {
			if (dir == 0)	now.first++;
			if (dir == 1)	now.second--;
			if (dir == 2)	now.first--;
			if (dir == 3)	now.second++;
			vis.push_back(now);
			left = min(left, now.second);
			right = max(right, now.second);
		}
		dir = (dir + 4) % 4;
	}
	sort(vis.begin(), vis.end());
	for (int i = vis[0].first; i <= vis[vis.size() - 1].first; i++) {
		for (int j = left; j <= right; j++) {
			bool ex = 0;
			for (ii k : vis) {
				if (make_pair(i, j) == k)	ex = 1;
			}
			cout << (ex ? '.' : '#');
		}
		cout << '\n';
	}
}