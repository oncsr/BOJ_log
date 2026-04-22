#include <iostream>
using namespace std;

int l;
string a;
string ans;

void solve(int n, int s) {
	if (n == l) {
		if (s == 0)	ans = a;
		return;
	}
	if (a[n] == 'G') {
		a[n] = '(';
		solve(n + 1, s + 1);
		a[n] = ')';
		solve(n + 1, s - 1);
	}
	else if (a[n] == '(')	solve(n + 1, s + 1);
	else	solve(n + 1, s - 1);
}

int main() {
	cin >> l >> a;
	solve(0, 0);
	cout << ans;
}