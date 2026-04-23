#include <iostream>
#include <stack>
using namespace std;

int main() {
	int c = 0, N, mx = 0, l = 0, r = 0;
	string s, temp = "";
	stack<char> S;
	cin >> N >> s;
	for (char i : s) {
		if (S.empty()) {
			c++;
			S.push(i);
			mx = max(mx, c);
			if (i == '(')	l++;
			else	r++;
		}
		else if (S.top() == '(') {
			if (i == '(') {
				c++;
				mx = max(mx, c);
				S.push(i);
				l++;
			}
			else {
				S.pop();
				c--;
				r++;
			}
		}
		else {
			if (i == '(') {
				S.pop();
				c--;
				l++;
			}
			else {
				c++;
				mx = max(mx, c);
				S.push(i);
				r++;
			}
		}
	}
	if (l != r)	cout << -1;
	else	cout << mx;
}