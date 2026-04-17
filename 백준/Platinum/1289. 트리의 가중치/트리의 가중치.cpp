#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, mod = 1'000'000'007;
ll temp1[100001]{}, temp2[100001]{}, temp3[100001]{};
vector<vector<pair<int, ll>>> V(100001);

ll power(ll n, ll p) {
	if (p == 0)	return 1;
	if (p == 1)	return n;
	ll g = power(n, p / 2);
	if (p & 1)	return g * g % mod * n % mod;
	return g * g % mod;
}

void dfs(int n, int p) {
	for (auto [i, c] : V[n]) {
		if (i == p)	continue;
		dfs(i, n);
		temp1[n] += (temp1[i] + 1) * c;
		temp1[n] %= mod;
		temp2[n] += temp1[i] + temp2[i];
		temp2[n] %= mod;
	}
}

void dfs2(int n, int p) {
	for (auto [i, c] : V[n]) {
		if (i == p)	continue;
		temp3[i] = (temp3[n] + (temp1[n] - (temp1[i] + 1) * c % mod + mod)) * c % mod;
		dfs2(i, n);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		V[a].emplace_back(b, c);
		V[b].emplace_back(a, c);
	}
	dfs(1, 0);
	dfs2(1, 0);
	ll res1 = 0, res2 = 0;
	for (int i = 1; i <= N; i++) {
		res1 += temp1[i];
		res1 %= mod;
		res2 += temp3[i];
		res2 %= mod;
	}
	cout << (res1 + (res2 * power(2, mod - 2) % mod) % mod) % mod;

}