#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, Q;
	cin >> N >> Q;

	ll X[200001]{}, S[200001]{};
	for (int i = 1; i <= N; i++) {
		cin >> X[i];
		S[i] = S[i - 1] + X[i];
	}

	for (; Q--;) {
		int L, R;
		cin >> L >> R;
		ll l = lower_bound(X + 1, X + N + 1, L) - X;
		ll r = upper_bound(X + 1, X + N + 1, R) - X - 1;

		if (r <= l) { cout << "0\n"; continue; }

		ll m = (l + r) >> 1;
		ll Vl = S[r] - S[l] - X[l] * (r - l);
		ll Vr = (r - l) * X[r] - (S[r - 1] - S[l - 1]);
		ll Vm = ((m - l) * X[m] - (S[m - 1] - S[l - 1])) + (S[r] - S[m] - (r - m) * X[m]);

		cout << max(Vl, Vr) - Vm << '\n';

	}

}