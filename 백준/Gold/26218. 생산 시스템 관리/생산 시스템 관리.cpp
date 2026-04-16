#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, B;
	cin >> N >> B;
	vector<ll> D(B + 1);
	vector<vector<int>> P(B + 1, vector<int>(N));
	D[0] = 1;
	vector<tuple<ll, ll, ll>> info(N);
	for (auto& [p, a, c] : info) {
		cin >> p >> a >> c;
		D[0] *= p;
	}

	int x = 0;
	for (auto& [p, a, c] : info) {
		vector<ll> nd(B + 1);
		vector<vector<int>> np(B + 1, vector<int>(N));
		for (int i = B; i >= 0; i--) {
			for (ll q = 1; i - c * q >= 0; q++) {
				if (!D[i - c * q])	continue;
				ll res = D[i - c * q] / p * min(100LL, p + a * q);
				if (res > nd[i]) {
					nd[i] = res;
					np[i] = P[i - c * q];
					np[i][x] = q;
				}
                if(p + a*q > 100)    break;
			}
		}
		for (int i = 0; i <= B; i++) {
			if (nd[i] > D[i]) {
				D[i] = nd[i];
				P[i] = np[i];
			}
		}
		x++;
	}
	
	int p = max_element(D.begin(), D.begin() + B + 1) - D.begin();
	cout << D[p] << '\n';
	for (int i : P[p])	cout << i << ' ';
	

}