#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	stack<pair<ll, ll>> S;
	int N;
	for (cin >> N; N--;) {
		ll o, a;
		cin >> o >> a;
		if (o == 1) { S.emplace(a, 1); continue; }
		if (S.empty())	continue;
		ll K = max(0LL, S.top().first - a);
		ll cnt = 0;
		while (!S.empty() && S.top().first >= K) {
			cnt += S.top().second;
			S.pop();
		}
		if (K)	S.emplace(K, cnt);
	}
	ll ans = 0;
	while (!S.empty())	ans += S.top().first * S.top().second, S.pop();
	cout << ans;

}