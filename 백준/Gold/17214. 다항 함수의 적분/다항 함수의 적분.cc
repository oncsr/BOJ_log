#include <iostream>
using namespace std;

int main() {
	string a;
	cin >> a;
	bool find_x = false, find_behind = false;
	int idx = -1, idp = -1;
	char op = 'e';
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == 'x')	find_x = true, idx = i;
		if (a[i] == '+' || (a[i] == '-' && i))	find_behind = true, idp = i, op = a[i];
	}
	if (find_x) {
		int s = 0, g = 1;
		for (int i = idx - 1; i >= 0; i--) {
			if (a[i] == '-') {
				if (s == 0)	s = -1;
				else	s *= -1;
			}
			else {
				s += (a[i] - '0') * g;
				g *= 10;

			}
		}
		if (s == 0)	s = 1;

		if (s == -2)	cout << '-';
		else if (s != 2)	cout << s / 2;

		cout << "xx";

		if (find_behind) {
			s = 0, g = 1;
			for (int i = a.size() - 1; i >= idp; i--) {
				if (a[i] == '-') {
					s *= -1;
				}
				else if (a[i] == '+')	continue;
				else {
					s += (a[i] - '0') * g;
					g *= 10;
				}
			}
			if (s == 1)	cout << '+';
			else if (s == -1)	cout << '-';
			else if (s > 0)	cout << '+' << s;
			else	cout << s;
			cout << "x+W";
		}
		else {
			cout << "+W";
		}
	}
	else {
		int s = 0, g = 1;
		for (int i = a.size() - 1; i >= 0; i--) {
			if (a[i] == '-') {
				s *= -1;
			}
			else {
				s += (a[i] - '0') * g;
				g *= 10;
			}
		}
		if (s == 0) {
			cout << 'W';
		}
		else {
			if (s == -1)	cout << '-';
			else if (s != 1)	cout << s;
			cout << "x+W";
		}
	}
}