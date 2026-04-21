#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int X, T;
	cin >> X >> T;
	if (X % 8 == 0) {
		if (X / 8 > T)	cout << -1;
		else	cout << 1 << '\n' << T - X / 8 << ' ' << 8;
	}
	else if (X % 4 == 0) {
		if (X / 4 > T) {
			if (X / 8 + 1 > T)	cout << -1;
			else {
				cout << 2 << '\n';
				cout << T - X / 8 - 1 << ' ' << 8 << '\n' << T - 1 << ' ' << 4;
			}
		}
		else {
			cout << 1 << '\n';
			cout << T - X / 4 << ' ' << 4;
		}
	}
	else {
		if (X <= T) {
			cout << 1 << '\n';
			cout << T - X << ' ' << 1;
		}
		else {
			if (X / 8 + X % 8 <= T) {
				cout << 2 << '\n';
				cout << T - X / 8 - (X % 8) << ' ' << 8 << '\n' << T - X % 8 << ' ' << 1 << '\n';
			}
			else {
				int a = X / 8, b = (X % 8) / 4, c = (X % 8) % 4;
				if (a && b && c) {
					if (a + b + c <= T) {
						cout << 3 << '\n';
						cout << T - a - b - c << ' ' << 8 << '\n';
						cout << T - b - c << ' ' << 4 << '\n';
						cout << T - c << ' ' << 1;
					}
					else	cout << -1;
				}
				else {
					if (a == 0 && b == 0) {
						if (c <= T) {
							cout << 1 << '\n';
							cout << T - c << ' ' << 1;
						}
						else	cout << -1;
					}
					else if (a == 0) {
						if (b + c <= T) {
							cout << 2 << '\n';
							cout << T - b - c << ' ' << 4 << '\n';
							cout << T - c << ' ' << 1;
						}
						else	cout << -1;
					}
					else if (b == 0) {
						if (a + c <= T) {
							cout << 2 << '\n';
							cout << T - a - c << ' ' << 8 << '\n';
							cout << T - c << ' ' << 1;
						}
						else	cout << -1;
					}
				}
			}
		}
	}

}