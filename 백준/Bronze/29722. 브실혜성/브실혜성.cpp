#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int y, m, d, n;
	char i;
	cin >> y >> i >> m >> i >> d >> n;

	int s = d + (m - 1) * 30 + (y - 1000) * 360;
	s += n;
	int Y = (s-1) / 360 + 1000;
	cout << Y << '-';
	s -= (Y-1000) * 360;
	int M = (s - 1) / 30 + 1;
	if (M < 10)	cout << '0';
	cout << M << '-';
	s -= (M-1) * 30;
	if (s < 10)	cout << '0';
	cout << s;
}