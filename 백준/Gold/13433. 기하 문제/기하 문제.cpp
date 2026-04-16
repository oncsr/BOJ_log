#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	vector<ll> arr(n);
	for (auto& i : arr)    cin >> i;
	vector<int> ord(n);
	for (int i = 0; i < n; i++)    ord[i] = i;

	ld ans = 1e18;

	do {
		vector<ld> bot(n);
		for (int i = 1; i < n; i++) {
			ll ri = arr[ord[i]];
			for (int j = i - 1; j >= 0; j--) {
				ll rj = arr[ord[j]];

				ll C = ri + rj, B = abs(ri - rj);
				ld F = sqrt(C * C - B * B);
				bot[i] = max(bot[i], bot[j] + F);

			}
		}
		ld D = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				D = max(D, bot[j] - bot[i]);
			}
		}
		ans = min(ans, D);

	} while (next_permutation(ord.begin(), ord.end()));

	cout.precision(20);
	cout << fixed << ans;

}