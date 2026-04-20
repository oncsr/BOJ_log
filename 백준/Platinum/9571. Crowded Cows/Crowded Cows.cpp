#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

ii arr[50001]{};
int seg[131073]{};

void init(int s, int e, int n) {
	if (s == e) {
		seg[n] = arr[s].second;
		return;
	}
	int m = (s + e) >> 1;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

int find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return max(find(s, m, l, r, n * 2), find(m + 1, e, l, r, n * 2 + 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, D;
	cin >> N >> D;

	for (int i = 1; i <= N; i++)	cin >> arr[i].first >> arr[i].second;
	sort(arr + 1, arr + N + 1);

	int idx[50001]{};
	for (int i = 1; i <= N; i++)	idx[i] = arr[i].first;

	init(1, N, 1);
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int left = lower_bound(idx + 1, idx + i + 1, idx[i] - D) - idx;
		int right = upper_bound(idx + i, idx + N + 1, idx[i] + D) - idx - 1;
		if (find(1, N, left, i - 1, 1) >= arr[i].second * 2 && find(1, N, i + 1, right, 1) >= arr[i].second * 2)	ans++;
	}
	cout << ans;

}