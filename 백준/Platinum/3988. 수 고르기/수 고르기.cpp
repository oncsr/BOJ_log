#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int arr[1000000]{}, N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	sort(arr, arr + N);

	int m = 10000001;
	priority_queue<ii, vector<ii>, greater<> > Q;

	for (int i = 1; i < N; i++) {
		Q.push({ arr[i] - arr[i - 1], i });
		if (i < N - K - 1)	continue;
		while (Q.top().second <= i - (N - K))	Q.pop();
		m = min(m, Q.top().first + arr[i] - arr[i - (N - K) + 1]);
	}
	cout << m;
}