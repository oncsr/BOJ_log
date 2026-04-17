#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, arr[101]{}, ans = 0, deg[101]{};
	cin >> N;
	vector<vector<int>> V(101);
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	bool con = 0;
	for (int i = 1; i <= N; i++) {
		int left = 1e9, right = 1e9;
		if (i != 1)	left = arr[i] - arr[i - 1];
		if (i != N)	right = arr[i + 1] - arr[i];
		if (right < left)	V[i].push_back(i + 1), deg[i + 1]++;
		else	V[i].push_back(i - 1), deg[i - 1]++;
	}
	int vis[101]{};
	function<void(int)> dfs = [&](int n) -> void {
		for (int i : V[n]) {
			if (vis[i])	continue;
			deg[i]--;
			vis[i]++;
			dfs(i);
		}
	};
	while (1) {
		bool con = 0;
		for (int i = 1; i <= N; i++) {
			if (vis[i])	continue;
			if (deg[i])	continue;
			vis[i]++;
			dfs(i);
			ans++;
			con = 1;
			break;
		}
		if (con)	continue;
		for (int i = 1; i <= N; i++) {
			if (vis[i])	continue;
			vis[i]++;
			dfs(i);
			ans++;
			con = 1;
			break;
		}
		if (!con)	break;

	}
	cout << ans;
}