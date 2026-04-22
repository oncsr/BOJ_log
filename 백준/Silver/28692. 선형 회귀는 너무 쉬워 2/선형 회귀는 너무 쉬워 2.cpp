#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll Sx = 0, Sy = 0, Sxx = 0, Sxy = 0;
	ll N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		ll x, y;
		cin >> x >> y;
		Sx += x;
		Sy += y;
		Sxx += x * x;
		Sxy += x * y;
	}
	if (Sx * Sx == N * Sxx)	cout << "EZPZ";
	else {
		double a, b;
		a = N * Sxy - Sx * Sy;
		a /= (double)(N * Sxx - Sx * Sx);
		b = Sy - a * Sx;
		b /= (double)N;
		cout << fixed;
		cout.precision(9);
		cout << a << ' ' << b;
	}
}