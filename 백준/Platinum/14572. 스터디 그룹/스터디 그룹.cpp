#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K, D;
	cin >> N >> K >> D;
	vector<tuple<int, int, vector<int>>> arr(N);
	for (auto& [M, d, a] : arr) {
		cin >> M >> d;
		a.resize(M);
		for (int& i : a)	cin >> i;
	}

	sort(arr.begin(), arr.end(), [&](auto a, auto b) {
		return get<1>(a) < get<1>(b);
	});

	int ans = 0, pos = 0;
	int S[31]{};
	for (int i = 0; i < N; i++) {
		auto [num, power, V] = arr[i];
		while (power - get<1>(arr[pos]) > D) {
			auto [num2, power2, V2] = arr[pos];
			for (int j : V2)	S[j]--;
			pos++;
		}
		for (int j : V)	S[j]++;

		int a = 0, b = 0;
		for (int j = 1; j <= K; j++) {
			int cnt = S[j];
			if (cnt)	a++;
			if (i - pos + 1 == cnt)	b++;
		}
		ans = max(ans, (a - b) * (i - pos + 1));
	}
	cout << ans;

}