#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int N;
vector<priority_queue<ii, vector<ii>, greater<>>> H(200002);
pair<int, int> ans[200001]{};

void dfs(int n, int d, int l, int r, int v) {
	// 왼쪽 자식 있는지 확인
	if (!H[d + 1].empty()) {
		auto [nv, x] = H[d + 1].top();
		if (l < nv && nv < v) {
			H[d + 1].pop();
			ans[n].first = x;
			dfs(x, d + 1, l, v, nv);
		}
		else	ans[n].first = -1;
	}
	else	ans[n].first = -1;
	if (!H[d + 1].empty()) {
		auto [nv, x] = H[d + 1].top();
		if (v < nv && nv < r) {
			H[d + 1].pop();
			ans[n].second = x;
			dfs(x, d + 1, v, r, nv);
		}
		else	ans[n].second = -1;
	}
	else	ans[n].second = -1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		H[b].emplace(a, i);
	}

	if (H[1].size() != 1)	return cout << -1, 0;
	int root = H[1].top().second, v = H[1].top().first;
	H[1].pop();
	dfs(root, 1, -2'147'483'647, 2'147'483'647, v);

	for (int i = 1; i <= N; i++)	if (!H[i].empty())	return cout << -1, 0;
	for (int i = 1; i <= N; i++)	cout << ans[i].first << ' ' << ans[i].second << '\n';

}