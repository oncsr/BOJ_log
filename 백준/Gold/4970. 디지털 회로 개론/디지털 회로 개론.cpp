#include <iostream>
using namespace std;
using ll = long long;

int pos = 0;
string a;

int solve(int p, int q, int r) {
	bool L = true, R = false, AND = false, NOT = false;
	int left = -1, right = -1;
	int val = -1;
	while (pos < a.size()) {
		char ch = a[pos++];
		if (ch == '(') {
			val = solve(p, q, r);
			if (left == -1) {
				if (NOT) {
					if (val == 0)	val = 2;
					else if (val == 2)	val = 0;
				}
				left = val;
			}
			else {
				if (NOT) {
					if (val == 0)	val = 2;
					else if (val == 2)	val = 0;
				}
				right = val;
			}
			continue;
		}
		if (ch == ')') {
			if (AND) {
				if (left == 0 || right == 0)	return 0;
				if (left == 1 || right == 1)	return 1;
				return 2;
			}
			if (left == 2 || right == 2)	return 2;
			if (left == 1 || right == 1)	return 1;
			return 0;
		}
		if (ch == '-') {
			NOT ^= 1;
			continue;
		}
		if (ch == '0')	val = 0;
		if (ch == '1')	val = 1;
		if (ch == '2')	val = 2;
		if (ch == 'P')	val = p;
		if (ch == 'Q')	val = q;
		if (ch == 'R')	val = r;
		if (ch == '*' || ch == '+') {
			if (ch == '*')	AND = 1;
			L = false, R = true;
			val = -1;
			NOT = 0;
		}
		if (L) {
			if (val != -1) {
				if (NOT) {
					if (val == 0)	val = 2;
					else if (val == 2)	val = 0;
				}
				left = val;
			}

		}
		else {
			if (val != -1) {
				if (NOT) {
					if (val == 0)	val = 2;
					else if (val == 2)	val = 0;
				}
				right = val;
			}
		}
	}
	return left;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	for (cin >> a; a != "."; cin >> a) {
		
		int cnt = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					pos = 0;
					if (solve(i, j, k) == 2)	cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
}