#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	vector<ll> S(N);
	vector<ll> E(N);
	vector<ll> V(M);
	for (int i = 0; i < N; i++)	cin >> S[i] >> E[i];
	for (int i = 0; i < M; i++)	cin >> V[i];
	sort(V.begin(), V.end());
	vector<ll> A, B;
	for (int i = 0; i < M - 1; i++) {
		ll val = V[i + 1] - V[i];
		if (i & 1)	B.push_back(val);
		else	A.push_back(val);
	}
	for (int i = 1; i < A.size(); i++)	A[i] += A[i - 1];
	for (int i = 1; i < B.size(); i++)	B[i] += B[i - 1];
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		int L, R;
		if (S[i] < E[i]) {
			L = upper_bound(V.begin(), V.end(), S[i]) - V.begin();
			R = lower_bound(V.begin(), V.end(), E[i]) - V.begin();
			R--;
			if (L > R)	continue;
			ll G = V[L] - S[i];
			if (R - L >= 2) {
				if (L & 1) {
					G += A[(R - 1) / 2];
					if (L / 2 + 1)	G -= A[L / 2];
				}
				else {
					G += B[R / 2 - 1];
					if (L / 2)	G -= B[L / 2 - 1];
				}
			}
			ans += G;
		}
		else {
			L = upper_bound(V.begin(), V.end(), E[i]) - V.begin();
			R = lower_bound(V.begin(), V.end(), S[i]) - V.begin();
			R--;
			if (L > R)	continue;
			ll G = S[i] - V[R];
			if (R - L >= 2) {
				if (R & 1) {
					G += B[R / 2 - 1];
					if (L / 2)	G -= B[L / 2 - 1];
				}
				else {
					G += A[R / 2 - 1];
					if ((L + 1) / 2)	G -= A[(L + 1) / 2 - 1];
				}
			}
			ans += G;
		}
	}
	cout << ans;
}