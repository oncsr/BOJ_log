#include <bits/stdc++.h>
using namespace std;

int arr[8]{}, n, m;
vector<vector<int>> res;

void solve(vector<int> choice, vector<int> now, int sel) {
	if (sel == m) {
		res.push_back(now);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (choice[i])	continue;
		choice[i] = 1;
		now.push_back(arr[i]);
		solve(choice, now, sel + 1);
		choice[i] = 0;
		now.pop_back();
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> arr[i];

	vector<int> choice(n);
	solve(choice, {}, 0);

	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	for (vector<int> i : res) {
		for (int j : i)	cout << j << ' ';
		cout << '\n';
	}
}