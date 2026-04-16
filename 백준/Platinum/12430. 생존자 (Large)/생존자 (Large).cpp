#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;

		vector<ii> arr(N);
		for (auto& [a, b] : arr)	cin >> a >> b;
		sort(arr.begin(), arr.end(), [](ii a, ii b) -> bool {
			auto [p, q] = a;
			auto [r, s] = b;
			return p + q < r + s;
		});

		vector<int> D(101001);
		int mx = 0;
		D[0] = 1;
		for (int i = 0; i < N; i++) {
			auto [p, s] = arr[i];
			for (int j = min(mx, p); j >= 0; j--) {
				if (!D[j])	continue;
				D[j + s] = 1;
				mx = max(mx, j + s);
			}
		}

		cout << "Case #" << tc << ": ";
		cout << mx << '\n';

	}

}