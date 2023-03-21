#include <iostream>
#include <algorithm>
using namespace std;
using ii = pair<int, int>;

bool cmp(ii a, ii b) {
	if (a.second == b.second)	return a.first < b.first;
	return a.second < b.second;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, s = 0;
	ii arr[100000]{};
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N, cmp);
	int ans = 1;
	ii now = arr[0];
	for (int i = 1; i < N; i++) {
		if (arr[i].first >= now.second)	ans++, now = arr[i];
	}
	cout << ans;
}