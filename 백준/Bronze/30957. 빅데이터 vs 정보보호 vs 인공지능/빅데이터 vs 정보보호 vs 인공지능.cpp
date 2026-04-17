#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	int s = 0, b = 0, a = 0, mx = 0;
	for (int i = 0; i < N; i++) {
		char t;
		cin >> t;
		s += t == 'S';
		b += t == 'B';
		a += t == 'A';
		mx = max({ mx, s, b, a });
	}
	if (s == b && b == a)	cout << "SCU";
	else {
		if (b == mx)	cout << 'B';
		if (s == mx)	cout << 'S';
		if (a == mx)	cout << 'A';
	}

}