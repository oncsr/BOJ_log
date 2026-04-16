#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, Q, inf = 1e18;
	vector<vector<ll>> D(201, vector<ll>(201, inf));
	cin >> N >> Q;
	vector<pair<ll, ll>> A(N);
	vector<ll> P;
	for (auto& [a, b] : A)	cin >> a >> b, P.push_back(a), P.push_back(b);
	sort(P.begin(), P.end());
	P.erase(unique(P.begin(), P.end()), P.end());
	N = P.size();
	for (auto& [a, b] : A) {
		ll c = b - a + 1;
		a = lower_bound(P.begin(), P.end(), a) - P.begin() + 1;
		b = lower_bound(P.begin(), P.end(), b) - P.begin() + 1;
		for (int s = a; s <= b; s++)for (int e = s; e <= b; e++)	D[s][e] = min(D[s][e], c);
	}

	for (int i = 1; i <= N; i++)for (int j = i; j <= N; j++) {
		for (int k = i; k <= j; k++)	D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
	}

	for (ll a, b; Q--;) {
		cin >> a >> b;
		int p = upper_bound(P.begin(), P.end(), a) - P.begin();
		if (!p) { cout << "-1\n"; continue; }
		p--;
		int q = lower_bound(P.begin(), P.end(), b) - P.begin();
		if (q == P.size()) { cout << "-1\n"; continue; }
		cout << (D[p + 1][q + 1] == inf ? -1 : D[p + 1][q + 1]) << '\n';
	}

}