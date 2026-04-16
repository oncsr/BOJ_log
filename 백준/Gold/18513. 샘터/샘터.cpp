#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

	int N, K;
	cin >> N >> K;
	map<int, ll> M;
	queue<pair<int, ll>> Q;
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		M[a] = 1;
		Q.emplace(a, 1);
	}
	while (!Q.empty()) {
		auto [n, t] = Q.front();
		Q.pop();
		if (t != 1)	ans += t - 1, K--;
		if (!K)	return cout << ans, 0;
		if (!M[n - 1]) {
			M[n - 1] = t + 1;
			Q.emplace(n - 1, t + 1);
		}
		if (!M[n + 1]) {
			M[n + 1] = t + 1;
			Q.emplace(n + 1, t + 1);
		}
	}

}