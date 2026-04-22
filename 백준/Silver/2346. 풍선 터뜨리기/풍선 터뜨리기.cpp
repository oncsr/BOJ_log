#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	deque<ii> D;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		D.push_back({ a, i + 1 });
	}
	while (D.size() > 1) {
		int cnt = D[0].first;
		cout << D[0].second << ' ';
		D.pop_front();
		if (cnt > 0)	cnt--;
		while (cnt > 0) {
			D.push_back(D.front());
			D.pop_front();
			cnt--;
		}
		while (cnt < 0) {
			D.push_front(D.back());
			D.pop_back();
			cnt++;
		}
	}
	cout << D[0].second;
}