#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		int N, c = 0;
		cin >> N;
		vector<tuple<int, int, int>> arr(N);
		for (auto& [a, b, x] : arr)	cin >> a >> b, x = c++;

		vector<int> D(N);
		auto A = arr;
		sort(A.begin(), A.end());
		int mn = N + 1;
		for (auto [_, a, x] : A) {
			if (a > mn)	D[x]++;
			mn = min(mn, a);
		}

		auto B = arr;
		sort(B.begin(), B.end(), [](auto a, auto b) -> bool {
			if (get<1>(a) == get<1>(b))	return get<0>(a) < get<0>(b);
			return get<1>(a) < get<1>(b);
			});
		mn = N + 1;
		for (auto [a, _, x] : B) {
			if (a > mn)	D[x]++;
			mn = min(mn, a);
		}

		int ans = 0;
		for (int i = 0; i < N; i++)	if (!D[i])	ans++;
		cout << ans << '\n';

	}

}