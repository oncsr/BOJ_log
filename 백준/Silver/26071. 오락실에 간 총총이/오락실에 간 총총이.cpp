#include <iostream>
using namespace std;

int main() {
	string a;
	int N, u = 1501, d = 0, r = 0, l = 1501, g = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		for (int j = 0; j < N; j++) {
			if (a[j] == 'G') {
				g++;
				u = min(u, i);
				d = max(d, i);
				r = max(r, j);
				l = min(l, j);
			}
		}
	}
	int s = 0;
	if (u != d) {
		if (d < N - 1 - u)	s += d;
		else	s += (N - 1 - u);
	}
	if (r != l) {
		if (r < N - 1 - l)	s += r;
		else	s += (N - 1 - l);
	}
	cout << (g == 1 ? 0 : s);
}