#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, mod = 1e9 + 7;
	cin >> N;
	ll F[100001]{}, L[100001]{}, R[100001]{}, S[100001]{};
	F[0] = L[0] = R[0] = S[0] = 1;

	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		F[i] = (F[a] + F[b]) % mod;
		L[i] = (L[a] + L[b] + F[b] + mod - 1) % mod;
		R[i] = (R[a] + R[b] + F[a] + mod - 1) % mod;
		S[i] = (S[a] + S[b] + F[b] * R[a] + F[a] * L[b] + mod - 1) % mod;
		cout << S[i] << '\n';
	}

}