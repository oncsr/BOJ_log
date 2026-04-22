#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		int L = 2100, R = 2399;
		int X = (L + R + 1) >> 1;
		int left1 = -1, left2 = -1, RR = 2399;
		int Q = 0;
		int f;
		bool goora = false;
		while (Q < 3 && L <= R) {
			cout << "? " << X << endl;
			cin >> f;
			Q++;
			if (!f) {
				R = X - 1;
				RR = X - 1;
			}
			else {
				if (left1 == -1)	left1 = X;
				else if (left2 == -1)	left2 = X;
				else {
					left1 = left2;
					left2 = X;
				}
				L = X;
			}
			X = (L + R + 1) >> 1;
		}
		if (left1 != -1) {
			if (left2 != -1) {
				cout << "? " << left2 << endl;
				cin >> f;
				if (!f)	L = left1, R = left2 - 1, goora = true;
				else	L = left2, R = RR;
			}
			else {
				cout << "? " << left1 << endl;
				cin >> f;
				if (!f)	L = 2100, R = left1 - 1, goora = true;
			}
		}
		X = (L + R + 1) >> 1;
		Q = 0;
		int LL = L;
		if (goora) {
			X = (L + R + 1) >> 1;
			while (L <= R) {
				cout << "? " << X << endl;
				cin >> f;
				if (!f) {
					R = X - 1;
					if (L == R) {
						cout << "! " << L << endl;
						break;
					}
				}
				else {
					L = X;
					if (L == R) {
						cout << "! " << X << endl;
						break;
					}
				}
				X = (L + R + 1) >> 1;
			}
			continue;
		}
		left1 = -1, left2 = -1, RR = R;
		while (Q < 3 && L <= R) {
			cout << "? " << X << endl;
			cin >> f;
			Q++;
			if (!f) {
				R = X - 1;
				RR = X - 1;
			}
			else {
				if (left1 == -1)	left1 = X;
				else if (left2 == -1)	left2 = X;
				else {
					left1 = left2;
					left2 = X;
				}
				L = X;
			}
			X = (L + R + 1) >> 1;
		}
		if (left1 != -1) {
			if (left2 != -1) {
				cout << "? " << left2 << endl;
				cin >> f;
				if (!f)	L = left1, R = left2 - 1, goora = true;
				else	L = left2, R = RR;
			}
			else {
				cout << "? " << left1 << endl;
				cin >> f;
				if (!f)	L = LL, R = left1 - 1, goora = true;
			}
		}
		if (goora) {
			X = (L + R + 1) >> 1;
			while (L <= R) {
				cout << "? " << X << endl;
				cin >> f;
				if (!f) {
					R = X - 1;
					if (L == R) {
						cout << "! " << L << endl;
						break;
					}
				}
				else {
					L = X;
					if (L == R) {
						cout << "! " << X << endl;
						break;
					}
				}
				X = (L + R + 1) >> 1;
			}
			continue;
		}
		X = (L + R + 1) >> 1;
		Q = 0;
		LL = L;
		//
		left1 = -1, left2 = -1, RR = R;
		while (Q < 3 && L <= R) {
			cout << "? " << X << endl;
			cin >> f;
			Q++;
			if (!f) {
				R = X - 1;
				RR = X - 1;
			}
			else {
				if (left1 == -1)	left1 = X;
				else if (left2 == -1)	left2 = X;
				else {
					left1 = left2;
					left2 = X;
				}
				L = X;
			}
			X = (L + R + 1) >> 1;
		}
		if (L > R) {
			L = LL;
			X = (L + R + 1) >> 1;
			cout << "? " << X << endl;
			cin >> f;
			if (!f) {
				cout << "! " << X - 1 << endl;
				continue;
			}
			cout << "? " << X + 1 << endl;
			cin >> f;
			if (!f) {
				cout << "! " << X << endl;
				continue;
			}
			cout << "! " << X + 1 << endl;
			continue;
		}
		if (left1 != -1) {
			if (left2 != -1) {
				cout << "? " << left2 << endl;
				cin >> f;
				if (!f) {
					cout << "! " << left2 - 1 << endl;
					continue;
				}
				cout << "! " << left2 << endl;
				continue;
			}
			else {
				cout << "? " << left1 << endl;
				cin >> f;
				if (!f) {
					cout << "! " << left1 - 1 << endl;
					continue;
				}
				cout << "! " << left1 << endl;
				continue;
			}
		}
		
	}
}