#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	ii arr[100000]{};
	for (int i = 0; i < N; i++) {
		int a, b, c, d;
		char t;
		cin >> a >> t >> b >> c >> t >> d;
		arr[i] = { (a - 2000) * 12 + b,(c - 2000) * 12 + d };
	}

	sort(arr, arr + N);
	int mx = 1, ans = arr[0].first;

	priority_queue<int, vector<int>, greater<> > Q;
	Q.push(arr[0].second);

	for (int i = 1; i < N; i++) {
		int s = arr[i].first, e = arr[i].second;
		while (!Q.empty() && s > Q.top())	Q.pop();
		Q.push(e);
		if (Q.size() > mx) {
			ans = s;
			mx = max(mx, (int)Q.size());
		}
	}
	if (ans % 12)	cout << ans / 12 + 2000 << '-';
	else	cout << (ans - 1) / 12 + 2000 << '-';
	int D = ans % 12;
	if (!D)	D = 12;
	if (D < 10)	cout << '0';
	cout << D;
}