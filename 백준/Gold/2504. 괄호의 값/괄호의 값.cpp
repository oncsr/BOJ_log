#include <bits/stdc++.h>
using namespace std;

int main() {
	string a;
	cin >> a;
	stack<int> S;
	for (char i : a) {
		if (i == '(')	S.push(-1);
		else if (i == '[')	S.push(-3);
		else if (i == ')') {
			int a = 0;
			bool find = 0;
			while (!S.empty()) {
				if (S.top() == -1) {
					S.pop();
					find = 1;
					break;
				}
				else if (S.top() == -3) {
					cout << 0;
					return 0;
				}
				else {
					a += S.top();
					S.pop();
				}
			}
			if (!find) {
				cout << 0;
				return 0;
			}
			if (!a)	S.push(2);
			else	S.push(2 * a);
		}
		else {
			int a = 0;
			bool find = 0;
			while (!S.empty()) {
				if (S.top() == -3) {
					S.pop();
					find = 1;
					break;
				}
				else if (S.top() == -1) {
					cout << 0;
					return 0;
				}
				else {
					a += S.top();
					S.pop();
				}
			}
			if (!find) {
				cout << 0;
				return 0;
			}
			if (!a)	S.push(3);
			else	S.push(3 * a);
		}
	}
	int s = 0;
	while (!S.empty()) {
		int a = S.top();
		if (a < 0) {
			cout << 0;
			return 0;
		}
		s += a;
		S.pop();
	}
	cout << s;
}