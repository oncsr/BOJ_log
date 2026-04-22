#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	ll p = 0, q = 0;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a == 0)	p++;
		if (a == 1)	q++;
	}

	cout << p * (p - 1) / 2 + p * (N - (p + q)) + 2 * p * q;
}