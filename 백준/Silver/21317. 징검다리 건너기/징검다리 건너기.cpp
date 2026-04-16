#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K, small[30]{}, big[30]{};
	cin >> N;
	for (int i = 0; i < N - 1; i++)	cin >> small[i] >> big[i];
	cin >> K;

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> Q;
	vector<vector<int>> D(30, vector<int>(2, -1));
	D[0][0] = 0;
	Q.emplace(0, 0, 0);
	while (!Q.empty()) {
		auto [d, n, t] = Q.top();
		Q.pop();
		if (d > D[n][t])	continue;
		if (n + 1 < N) {
			if (D[n + 1][t] == -1 || D[n + 1][t] > d + small[n]) {
				D[n + 1][t] = d + small[n];
				Q.emplace(D[n + 1][t], n + 1, t);
			}
		}
		if (n + 2 < N) {
			if (D[n + 2][t] == -1 || D[n + 2][t] > d + big[n]) {
				D[n + 2][t] = d + big[n];
				Q.emplace(D[n + 2][t], n + 2, t);
			}
		}
		if (n - 1 > 0) {
			if (D[n - 1][t] == -1 || D[n - 1][t] > d + small[n]) {
				D[n - 1][t] = d + small[n];
				Q.emplace(D[n - 1][t], n - 1, t);
			}
		}
		if (n - 2 > 0) {
			if (D[n - 2][t] == -1 || D[n - 2][t] > d + big[n]) {
				D[n - 2][t] = d + big[n];
				Q.emplace(D[n - 2][t], n - 2, t);
			}
		}
		if (t)	continue;
		if (n + 3 < N) {
			if (D[n + 3][1] == -1 || D[n + 3][1] > d + K) {
				D[n + 3][1] = d + K;
				Q.emplace(D[n + 3][1], n + 3, 1);
			}
		}
		if (n - 3 > 0) {
			if (D[n - 3][1] == -1 || D[n - 3][1] > d + K) {
				D[n - 3][1] = d + K;
				Q.emplace(D[n - 3][1], n - 3, 1);
			}
		}
	}
	if (D[N - 1][1] == -1)	cout << D[N - 1][0];
	else	cout << min(D[N - 1][0], D[N - 1][1]);

}