#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N, Q;
		cin >> N >> Q;
		ll A1, B1, C1, M1, A2, B2, C2, M2, A3, B3, C3, M3;
		vector<ll> X(max(3, N + 1)), Y(max(3, N + 1)), Z(max(3, Q + 1));
		cin >> X[1] >> X[2] >> A1 >> B1 >> C1 >> M1 >> Y[1] >> Y[2] >> A2 >> B2 >> C2 >> M2 >> Z[1] >> Z[2] >> A3 >> B3 >> C3 >> M3;

		for (int i = 3; i <= N; i++) {
			X[i] = (A1 * X[i - 1] + B1 * X[i - 2] + C1) % M1;
			Y[i] = (A2 * Y[i - 1] + B2 * Y[i - 2] + C2) % M2;
		}
		for (int i = 3; i <= Q; i++)	Z[i] = (A3 * Z[i - 1] + B3 * Z[i - 2] + C3) % M3;

		ll sum = 0;
		vector<ll> L, R, K;
		for (int i = 1; i <= N; i++) {
			L.push_back(min(X[i], Y[i]) + 1);
			R.push_back(max(X[i], Y[i]) + 1);
			sum += R.back() - L.back() + 1;
		}
		for (int i = 1; i <= Q; i++)	K.push_back(sum - Z[i]);

		vector<int> V;
		vector<ll> C;
		for (int i = 0; i < N; i++) {
			V.push_back(L[i]);
			V.push_back(-R[i] - 1);
		}
		sort(V.begin(), V.end(), [&](int a, int b) -> bool {
			if (abs(a) == abs(b))	return a > b;
			return abs(a) < abs(b);
			});

		ll s = 0, c = 1, prev = abs(V[0]) - 1;
		for (int i = 0; i < V.size(); i++) {
			c += s * (abs(V[i]) - prev);
			while (i < V.size() - 1 && abs(V[i]) == abs(V[i + 1])) {
				C.push_back(c);
				if (V[i] < 0)	s--;
				else	s++;
				i++;
			}
			C.push_back(c);
			if (V[i] < 0)	s--;
			else	s++;
			prev = abs(V[i]);
		}

		ll ans = 0;
		for (int i = 1; i <= Q; i++) {
			int pos = upper_bound(C.begin(), C.end(), K[i - 1]) - C.begin();
			if (pos == 0 || pos == C.size())	continue;
			ll q = abs(V[pos]), p = abs(V[pos - 1]);
			ll qcnt = C[pos], pcnt = C[pos - 1], d = (qcnt - pcnt) / (q - p);
			ll res = (K[i - 1] - pcnt) / d + p;
			ans += res * i;
		}
		cout << "Case #" << tc << ": " << ans << '\n';

	}
	
}