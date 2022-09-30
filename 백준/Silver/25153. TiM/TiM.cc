#include <iostream>
#include <stack>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, s = 0, k = 0, x = 0, r = 0;
	cin >> n >> m;
	stack<int> S;
	bool y = true;
	for (int i = 0; i < m; i++) {
		char a;
		cin >> a;
		if (a == 'X') {
			if (y)	x++;
			else	x--;
		}
		else if (a == '+' || a == '-') {
			int temp = 0;
			int g = 1;
			while (!S.empty()) {
				temp += g * S.top();
				S.pop();
				g *= 10;
			}
			k += temp;
			if (y)	r += temp;
			else	r -= temp;
			if (a == '+')	y = true;
			else	y = false;
		}
		else {
			s += (a - '0');
			S.push(a - '0');
		}
	}
	int temp = 0, g = 1;
	while (!S.empty()) {
		temp += g * S.top();
		S.pop();
		g *= 10;
	}
	k += temp;
	if (y)	r += temp;
	else	r -= temp;
	cout << s << '\n' << k << '\n' << -1 * r / x;
}