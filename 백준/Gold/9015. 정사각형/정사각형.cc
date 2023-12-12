#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		int N;
		cin >> N;
		vector<ii> arr(N);
		set<ii> S;
		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			arr[i] = make_pair(a, b);
			S.insert(arr[i]);
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				int dx = arr[i].first - arr[j].first;
				int dy = arr[i].second - arr[j].second;
				ii p1 = make_pair(arr[i].first - dy, arr[i].second + dx);
				ii p2 = make_pair(arr[j].first - dy, arr[j].second + dx);

				if (S.count(p1) && S.count(p2)) {
					ans = max(ans, dx * dx + dy * dy);
				}
			}
		}
		cout << ans << '\n';

	}

}