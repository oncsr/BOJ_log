#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, S;
	cin >> N >> S;
	vector<ii> arr(N);
	for (auto& i : arr)	cin >> i.first >> i.second;
	sort(arr.begin(), arr.end());

	vector<int> h(N);
	for (int i = 0; i < N; i++)	h[i] = arr[i].first;
	vector<int> dp(N), mx(N);
	for (int i = 0; i < N; i++) {
		if (!i) { dp[i] = mx[i] = arr[i].second; continue; }
		int pos = upper_bound(h.begin(), h.begin() + i, h[i] - S) - h.begin();
		pos--;
		if (pos >= 0)	dp[i] = mx[pos] + arr[i].second;
		else	dp[i] = arr[i].second;
		mx[i] = max(dp[i], mx[i - 1]);
	}
	cout << mx[N - 1];
}