#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;

bool cmp(pl a, pl b) {
	if (a.second == b.second)	return a.first < b.first;
	return a.second < b.second;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	ll min_x = 1e9 + 1, max_x = 0, min_y = 1e9 + 1, max_y = 0;
	cin >> N;
	pl arr[50000]{};
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
		min_x = min(min_x, arr[i].first);
		max_x = max(max_x, arr[i].first);
		min_y = min(min_y, arr[i].second);
		max_y = max(max_y, arr[i].second);
	}
	ll S = (max_x - min_x) * (max_y - min_y);
	sort(arr, arr + N);
	ll G = S;

	pl left[50000]{};
	left[0] = { arr[0].second, arr[0].second };
	for (int i = 1; i < N; i++) {
		left[i].first = min(left[i - 1].first, arr[i].second);
		left[i].second = max(left[i - 1].second, arr[i].second);
	}
	pl right = { 1e9, 0 };
	for (int i = N - 1; i > 0; i--) {
		right.first = min(right.first, arr[i].second);
		right.second = max(right.second, arr[i].second);

		ll area1 = (arr[i - 1].first - arr[0].first) * (left[i - 1].second - left[i - 1].first);
		ll area2 = (arr[N - 1].first - arr[i].first) * (right.second - right.first);
		G = min(G, area1 + area2);

	}
	sort(arr, arr + N, cmp);

	left[0] = { arr[0].first, arr[0].first };
	for (int i = 1; i < N; i++) {
		left[i].first = min(left[i - 1].first, arr[i].first);
		left[i].second = max(left[i - 1].second, arr[i].first);
	}
	right = { 1e9, 0 };
	for (int i = N - 1; i > 0; i--) {
		right.first = min(right.first, arr[i].first);
		right.second = max(right.second, arr[i].first);

		ll area1 = (arr[i - 1].second - arr[0].second) * (left[i - 1].second - left[i - 1].first);
		ll area2 = (arr[N - 1].second - arr[i].second) * (right.second - right.first);
		G = min(G, area1 + area2);
	}
	cout << S - G;
	


}