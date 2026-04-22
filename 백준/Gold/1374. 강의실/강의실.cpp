#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, t;
	cin >> N;

	ii arr[100000]{};
	for (int i = 0; i < N; i++)	cin >> t >> arr[i].first >> arr[i].second;
	sort(arr, arr + N);
	priority_queue<int, vector<int>, greater<> > Q;
	Q.push(arr[0].second);
	int ans = 1;
	for (int i = 1; i < N; i++) {
		while (!Q.empty() && arr[i].first >= Q.top())	Q.pop();
		Q.push(arr[i].second);
		ans = max(ans, (int)Q.size());
	}
	cout << ans;

}