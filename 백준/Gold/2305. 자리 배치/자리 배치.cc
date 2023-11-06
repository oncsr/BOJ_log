#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, K;
ll DG[51][51]{};
ll DF[51];

ll G(ll n, ll k) {
	if (k == 1)	return DG[n][k] = n - 1;
	if (DG[n][k])	return DG[n][k];
	ll sum = 0;
	for (int i = n - 2; i >= 2 * (k - 1); i--)	sum += G(i, k - 1);
	return DG[n][k] = sum;
}

ll F(ll n) {
	if (n <= 1)	return 1;
	if (n == 2)	return 2;
	if (DF[n])	return DF[n];
	ll sum = 1;
	for (int i = 1; i <= n / 2; i++)	sum += G(n, i);
	return DF[n] = sum;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K;
	ll ans = F(K - 1) * F(N - K);
	for (int i = 1; i <= N; i++) {
		// i를 자유석으로
		if (i == K)	continue;
		ll left, right;
		if (i < K) {
			left = F(i - 1) * F(K - 1 - i);
			for (int j = i - 2; j >= 0; j--)	left += F(j) * F(K - 1 - i);
			for (int j = K - 2 - i; j >= 0; j--)	left += F(j) * F(i - 1);
			right = F(N - K);
		}
		else {
			left = F(K - 1);
			right = F(i - K - 1) * F(N - i);
			for (int j = i - K - 2; j >= 0; j--)	right += F(j) * F(N - i);
			for (int j = N - i - 1; j >= 0; j--)	right += F(j) * F(i - K - 1);
		}
		ans += left * right;
	}
	cout << ans;

}