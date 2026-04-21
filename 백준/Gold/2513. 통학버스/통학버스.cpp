#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, K, S;
	cin >> N >> K >> S;
	pair<ll, ll> arr[30000]{};
	for (int i = 0; i < N; i++)	cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N);

	// arr[mid]부터 학교기준으로 오른쪽에 있음
	int mid = 0;
	for (; mid < N && arr[mid].first < S; mid++);
	ll ans = 0;
	int pos = 1;
	for (int i = 0; i < mid; i++) {
		if (!arr[i].second)	continue;
		ans += ((arr[i].second - 1) / K + 1) * abs(arr[i].first - S) * 2;
		if (arr[i].second % K == 0) {
			arr[i].second = 0;
			continue;
		}
		ll re = K - (arr[i].second % K);
		arr[i].second = 0;
		for (; pos < mid; pos++) {
			if (!arr[pos].second)	continue;
			ll sub = min(re, arr[pos].second);
			arr[pos].second -= sub;
			re -= sub;
			if (!re)	break;
		}
	}
	
	pos = N - 2;
	for (int i = N - 1; i >= mid; i--) {
		if (!arr[i].second)	continue;
		ans += ((arr[i].second - 1) / K + 1) * abs(arr[i].first - S) * 2;
		if (arr[i].second % K == 0) {
			arr[i].second = 0;
			continue;
		}
		ll re = K - (arr[i].second % K);
		arr[i].second = 0;
		for (; pos >= mid; pos--) {
			if (!arr[pos].second)	continue;
			ll sub = min(re, arr[pos].second);
			arr[pos].second -= sub;
			re -= sub;
			if (!re)	break;
		}
	}

	cout << ans;
}