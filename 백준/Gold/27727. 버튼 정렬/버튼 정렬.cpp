#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

ll arr[100001]{}, g = 0;
ii ord[100000]{};
int id = 0, N;
ll ans = 0, K;
bool cmp(ii a, ii b) {
	if (a.first == b.first)	return a.second > b.second;
	return a.first > b.first;
}

ll D(int s, int m, int e) {
	if (s > m)	return 0;
	ll right;
	if (m >= e)	right = 0;
	else	right = (arr[m] - arr[m - 1]) * ((ll)e - m) - (arr[e] - arr[m]);
	if (right) {
		ll left;
		if (m <= s)	left = 0;
		else	left = (arr[m] - arr[m - 1]) * ((ll)m - s) - (arr[m - 1] - arr[s - 1]);
		if (left + right <= K)	ans++;
		return left + right;
	}
	else {
		id++;
		if (id >= N)	return 0;
		ll score = (arr[m] - arr[m - 1] - (ll)ord[id].first);
		ll temp = (arr[m] - arr[m - 1] - (ll)ord[id].first) * ((ll)e - s);
		ll t2 = D(s, ord[id].second, m - 1);
		if (min(temp, K - t2) <= 0)	return temp + t2;
		ans += min(temp, K - t2) / ((ll)e - s);
		return temp + t2;
	}
}

int main() {

	cin.tie(0)->sync_with_stdio(0);

	//////////////////////////////////////////////////////

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		ord[i - 1] = { arr[i], i };
		arr[i] += arr[i - 1];
	}
	sort(ord, ord + N, cmp);
	cin >> K;
	ll G = D(1, ord[0].second, N);
	if (G <= K)	ans += (K - G) / (ll)N;
	cout << ans;
}

/*
* [shake! 2022]
*
* < 사용한 자료구조, 알고리즘 >
* divide and conquer
*
* < 참고한 자료 >
* x
*
* < 출처 >
* x
*
*/