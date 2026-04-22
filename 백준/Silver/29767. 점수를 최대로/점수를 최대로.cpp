#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	vector<ll> V;
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		ll a;
		cin >> a;
		V.push_back(a);
		if (!i)	continue;
		V[i] += V[i - 1];
	}
	sort(V.begin(), V.end(), greater<>());
	ll ans = 0;
	for (int i = 0; i < K; i++)	ans += V[i];
	cout << ans;
}