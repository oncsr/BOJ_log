#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
vector<vector<int>> arr;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	bool flip = false;
	if (N > M) {
		flip = true;
		swap(N, M);
	}

	arr = vector<vector<int>>(N, vector<int>(M));
	for (int i = 0, a; i < N * M; i++) {
		cin >> a;
		int x = i / M, y = i % M;
		if (flip) {
			x = i % N, y = i / N;
		}
		arr[x][y] = a;
	}

	ll ans = 0;
	for (int i = 0; i < N; i++) for (int j = i + 1; j < N; j++) {
		ll cnt[19]{};
		for (int k = 0; k < M; k++) {
			cnt[arr[i][k] + arr[j][k]]++;
		}
		for (int v = 2; v < 19; v++) {
			if (v == 10) {
				continue;
			}
			ans += cnt[v] * cnt[20 - v];
		}
		ans += cnt[10] * (cnt[10] - 1);
	}
	cout << (ans >> 1);

}