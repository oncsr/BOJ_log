#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, k;
	ll ans = 0, a, b;
	cin >> n >> k >> a;
	priority_queue<ll> Q;
	for (int i = 1; i < n; i++) {
		cin >> b;
		Q.push(b - a);
		a = b;
	}
	for (int i = 1; i < n; i++) {
		if (i >= k)	ans += Q.top();
		Q.pop();
	}
	cout << ans;

}