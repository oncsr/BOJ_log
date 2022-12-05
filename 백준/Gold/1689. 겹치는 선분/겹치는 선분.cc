#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, a, b;
	cin >> N;
	ii arr[1000000]{};
	for (int i = 0; i < N; i++)	cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N);
	int mx = 1;
	priority_queue<int, vector<int>, greater<> > Q;
	Q.push(arr[0].second);
	for (int i = 1; i < N; i++) {
		ii now = arr[i];
		if (now.first >= Q.top()) {
			while (!Q.empty() && now.first >= Q.top())
				Q.pop();
		}
		Q.push(now.second);
		mx = max(mx, (int)Q.size());
	}
	cout << mx;
}