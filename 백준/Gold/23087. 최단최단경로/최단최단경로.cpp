#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, X, Y;
	cin >> N >> M >> X >> Y;
	vector<vector<pair<int, ll>>> V(N + 1);
	for (int a, b, c, i = 0; i < M; i++) {
		cin >> a >> b >> c;
		V[a].emplace_back(b, c);
	}

	priority_queue<tuple<ll, int, ll, int>, vector<tuple<ll, int, ll, int>>, greater<>> Q;

	ll mod = 1e9 + 9;
	vector<ll> D(N + 1, -1);
	D[X] = 0;
	vector<int> R(N + 1, -1);
	R[X] = 0;
	vector<ll> C(N + 1);
	C[X] = 1;
	Q.emplace(0, 0, 1, X);

	while (!Q.empty()) {
		auto[d, r, c, n] = Q.top();
		Q.pop();
		if (d > D[n]) continue;
		for (auto[i, v] : V[n]) {
			if (D[i] == -1 || D[i] > d + v) {
				D[i] = d + v;
				R[i] = R[n] + 1;
				C[i] = C[n];
				Q.emplace(D[i], R[i], C[i], i);
			}
			else if (D[i] == d + v) {
				if (R[i] > r + 1) R[i] = r + 1;
				else if (R[i] == r + 1) C[i] = (C[i] + C[n]) % mod;
			}
		}
	}
	if (D[Y] == -1) return cout << -1, 0;
	cout << D[Y] << '\n' << R[Y] << '\n' << C[Y] % mod;

}