#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, t[100000]{}, mx = 0, s = 0, a, b, c;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		t[i] = s;
		cin >> a;
		s += a;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (c - t[a - 1] > 0) {
			int x = (c - t[a - 1] - 1) / s + 1;
			if (a > b)	mx = max(mx, (x + 1) * s + t[b - 1]);
			else	mx = max(mx, x * s + t[b - 1]);
		}
		else {
			if (a > b)	mx = max(mx, s + t[b - 1]);
			else	mx = max(mx, t[b - 1]);
		}
	}
	cout << mx;
}