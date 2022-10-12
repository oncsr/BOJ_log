#include <iostream>
using namespace std;

int main() {
	int e, r, s = 0, a, b, c, d[101]{};
	cin >> e >> r;
	for (; r--;) {
		cin >> a >> b >> c;
		int t = 0;
		for (int i = c; i < c + a; i++)	t = max(d[i], t);
		for (int i = c; i < c + a; i++)	d[i] = t + b;
		s = max(t + b, s);
	}
	cout << s;
}