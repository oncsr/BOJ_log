#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	map<ll, ll> C;
	ll N;
	cin >> N;
	ll ans = N * N, a;
	for (; N--; C[a]++)	cin >> a;
	for (auto& [a, b] : C)	ans -= b * b;
	cout << ans;

}