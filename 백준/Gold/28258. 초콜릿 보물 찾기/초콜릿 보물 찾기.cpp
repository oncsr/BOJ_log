#include <bits/stdc++.h>
using namespace std;

bool up_check(int x, int y) {
	int res;
	cout << "? " << x - 1 << ' ' << y << endl;
	cin >> res;
	return res;
}
bool down_check(int x, int y) {
	int res;
	cout << "? " << x + 1 << ' ' << y << endl;
	cin >> res;
	return res;
}
bool left_check(int x, int y) {
	int res;
	cout << "? " << x << ' ' << y - 1 << endl;
	cin >> res;
	return res;
}
bool right_check(int x, int y) {
	int res;
	cout << "? " << x << ' ' << y + 1 << endl;
	cin >> res;
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int x = 0, y = 2, res;
	for (int i = 0; i < 4; i++) {
		cout << "? " << x << ' ' << y << endl;
		cin >> res;
		if (res) {
			if (x > 0) {
				res = up_check(x, y);
				if (res) {
					cout << "! " << x << ' ' << y << ' ' << x - 1 << ' ' << y << endl;
					return 0;
				}
			}
			if (x < 9) {
				res = down_check(x, y);
				if (res) {
					cout << "! " << x << ' ' << y << ' ' << x + 1 << ' ' << y << endl;
					return 0;
				}
			}
			if (y > 0) {
				res = left_check(x, y);
				if (res) {
					cout << "! " << x << ' ' << y << ' ' << x << ' ' << y - 1 << endl;
					return 0;
				}
			}
			if (y < 9) {
				res = right_check(x, y);
				if (res) {
					cout << "! " << x << ' ' << y << ' ' << x << ' ' << y + 1 << endl;
					return 0;
				}
			}
		}
		y += 2;
	}
	for (int i = 1; i < 9; i++) {
		y = i & 1;
		x = i;
		for (int j = 0; j < 5; j++) {
			cout << "? " << x << ' ' << y << endl;
			cin >> res;
			if (res) {
				if (x > 0) {
					res = up_check(x, y);
					if (res) {
						cout << "! " << x << ' ' << y << ' ' << x - 1 << ' ' << y << endl;
						return 0;
					}
				}
				if (x < 9) {
					res = down_check(x, y);
					if (res) {
						cout << "! " << x << ' ' << y << ' ' << x + 1 << ' ' << y << endl;
						return 0;
					}
				}
				if (y > 0) {
					res = left_check(x, y);
					if (res) {
						cout << "! " << x << ' ' << y << ' ' << x << ' ' << y - 1 << endl;
						return 0;
					}
				}
				if (y < 9) {
					res = right_check(x, y);
					if (res) {
						cout << "! " << x << ' ' << y << ' ' << x << ' ' << y + 1 << endl;
						return 0;
					}
				}
			}
			y += 2;
		}
	}
	x = 9, y = 1;
	for (int i = 0; i < 4; i++) {
		cout << "? " << x << ' ' << y << endl;
		cin >> res;
		if (res) {
			res = up_check(x, y);
			if (res) {
				cout << "! " << x << ' ' << y << ' ' << x - 1 << ' ' << y << endl;
				return 0;
			}
			res = left_check(x, y);
			if (res) {
				cout << "! " << x << ' ' << y << ' ' << x << ' ' << y - 1 << endl;
				return 0;
			}
			cout << "! " << x << ' ' << y << ' ' << x << ' ' << y + 1 << endl;
			return 0;
		}
		y += 2;
	}
	x = 9, y = 9;
	cout << "? " << x << ' ' << y << endl;
	cin >> res;
	if (res) {
		res = up_check(x, y);
		if (res) {
			cout << "! " << x << ' ' << y << ' ' << x - 1 << ' ' << y << endl;
			return 0;
		}
		cout << "! " << x << ' ' << y << ' ' << x << ' ' << y - 1 << '\n';
		return 0;
	}
	x = 0, y = 1;
	cout << "? " << x << ' ' << y << endl;
	cin >> res;
	if (res) {
		cout << "! " << x << ' ' << y << ' ' << x << ' ' << y - 1 << endl;
		return 0;
	}
	cout << "! 0 0 1 0" << endl;
	return 0;
}