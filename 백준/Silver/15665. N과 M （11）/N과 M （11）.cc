#include <bits/stdc++.h>
using namespace std;

int arr[7]{}, n, m;
vector<vector<int>> res;

void solve(int sel, vector<int> now) {
	if (sel == m) {
		res.push_back(now);
		return;
	}
	for (int i = 0; i < n; i++) {
		now.push_back(arr[i]);
		solve(sel + 1, now);
		now.pop_back();
	}
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> arr[i];

	solve(0, {});

	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	for (vector<int> i : res) {
		for (int j : i)	cout << j << ' ';
		cout << '\n';
	}
}