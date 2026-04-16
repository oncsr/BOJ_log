#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll D, K;
	cin >> D >> K;
	ll A[31] = { 0,1,0 };
	ll B[31] = { 0,0,1 };
	for (int i = 3; i <= D; i++)	A[i] = A[i - 1] + A[i - 2], B[i] = B[i - 1] + B[i - 2];

	for (ll a = 1; A[D] * a < K; a++) {
		ll e = K - A[D] * a;
		if (e % B[D] == 0) {
			cout << a << '\n' << e / B[D];
			return 0;
		}
	}

}