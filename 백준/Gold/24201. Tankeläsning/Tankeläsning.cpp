#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll C[12] = { 0,1 }, n;
	vector<ll> CP(12, 1);
	for (cin >> n; n--;) {
		char o, a;
		cin >> o >> a;
		if (a == 'x') {
			if (o == '-')	C[1] -= CP[1];
			if (o == '+')	C[1] += CP[1];
			if (o == '*') {
				for (int i = 11; i > 0; i--)	C[i] = C[i - 1], CP[i] = CP[i - 1];
				C[0] = 0;
			}
		}
		else {
			ll g = a - '0';
			if (o == '-')	C[0] -= g * CP[0];
			if (o == '+')	C[0] += g * CP[0];
			if (o == '*') {
				for (int i = 0; i < 12; i++)	C[i] *= g;
			}
			if (o == '/') {
				for (int i = 0; i < 12; i++)	CP[i] *= g;
			}
		}
	}
	for (int i = 11; i > 0; i--) {
		if (C[i]) {
			cout << "Nej";
			return 0;
		}
	}
	if (C[0] && (abs(C[0]) % CP[0]))	cout << "Nej";
	else	cout << C[0] / CP[0];

}