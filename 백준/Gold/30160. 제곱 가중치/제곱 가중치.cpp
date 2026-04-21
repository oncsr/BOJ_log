#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll sum = 0, D = 0, F = 0, N;
	cin >> N >> D;
	F = sum = D;
	cout << F << ' ';
	for (int i = 1; i < N; i++) {
		ll a;
		cin >> a;
		D += 2 * sum + a;
		F += D;
		sum += a;
		cout << F << ' ';
	}


}