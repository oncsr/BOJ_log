#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		string a, b;
		cin >> a >> b;
		int as = a.size(), bs = b.size(), cc[80]{}, ta, tb;
		int bonus = 0, fz = 1;
		for (int i = as - 1, j = bs - 1; max(i, j) >= 0; i--, j--) {
			ta = (i < 0 ? 0 : a[i] - '0');
			tb = (j < 0 ? 0 : b[j] - '0');
			int val = ta + tb + bonus;
			cc[max(i, j)] = val % 2;
			if (val > 1)	bonus = 1;
			else	bonus = 0;
		}
		if (bonus) {
			cout << 1;
			fz = 0;
		}
		int i = 0;
		while (fz && !cc[i] && i < max(as, bs))	i++;
		if (i == max(as, bs))	cout << 0;
		for (; i < max(as, bs); i++)	cout << cc[i];
		cout << '\n';
	}
}