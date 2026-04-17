#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, M, K, ans = 1, mod = 1e9 + 7;
	cin >> N >> M >> K;
	if (K == 1 || K > N) {
		for (int i = 0; i < N; i++)	ans = (ans * M) % mod;
	}
	else if (K == N) {
		for (int i = 0; i < (N + 1) >> 1; i++)	ans = (ans * M) % mod;
	}
	else if (K & 1)	ans = M * M;
	else	ans = M;
	cout << ans;

}