#include <iostream>
#include <algorithm>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, s = 0;
	ii arr[100000]{};
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i].second >> arr[i].first;
	sort(arr, arr + N);
	int ans = 1;
	int now = arr[0].first;
	for (int i = 1; i < N; i++) {
		if (arr[i].second >= now)	ans++, now = arr[i].first;
	}
	cout << ans;
}