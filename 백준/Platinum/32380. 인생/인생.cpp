#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, U, D;
	cin >> N >> U >> D;
	ll A[300001]{}, B[300001]{}, V[300001]{}, diff[300001]{};
	for (int i = 1; i <= N; i++)	cin >> A[i];
	for (int i = 1; i <= N; i++)	cin >> B[i];

	ll ans = 0, d = 0;
	for (int i = 1; i <= N; i++) {
		ans += V[i];
		d += diff[i];
		if (A[i] < B[i]) {
			ans += A[i] + d;
			d += U;
			ll g = (B[i] - A[i] - 1) / (U + D) + 1;
			if (i + g <= N)	V[i + g] += B[i] - A[i] - (U + D) * (g - 1), diff[i + g] -= (U + D);
		}
		else {
			ans += B[i] + d;
			d -= D;
		}
		cout << ans << '\n';
	}

}