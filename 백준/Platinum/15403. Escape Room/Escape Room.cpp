#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	vector<vector<int>> cnt(N + 1);
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		cnt[a].push_back(i);
	}
	int mx = N;
	int ans[100001]{};
	for (int i = 1; i <= N; i++) {
		sort(cnt[i].begin(), cnt[i].end(), greater<>());
		int g = mx - cnt[i].size() + 1;
		for (int j : cnt[i])	ans[j] = g++;
		mx -= cnt[i].size();
	}

	for (int i = 1; i <= N; i++)	cout << ans[i] << ' ';

}