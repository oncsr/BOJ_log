#include <iostream>
using namespace std;
using ll = long long;

void solve(int s, int e, int v) {
	if (s == e) {
		cout << (v == 1 ? ' ' : '-');
		return;
	}
	int d = (e - s + 1) / 3;
	if (v == 1) {
		solve(s, s + d - 1, 1);
		solve(s + d, s + 2 * d - 1, 1);
		solve(s + 2 * d, e, 1);
	}
	else {
		solve(s, s + d - 1, 0);
		solve(s + d, s + 2 * d - 1, 1);
		solve(s + 2 * d, e, 0);
	}
}

int main() {
	int n;
	while (cin >> n) {
		int g = 1;
		while (n--)	g *= 3;
		solve(1, g, 0);
		cout << '\n';
	}
}