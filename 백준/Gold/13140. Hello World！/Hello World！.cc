#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int h, e, l, o, w, r, d;
	bool find = false;
	for (h = 1; h < 10; h++) {
		for (e = 0; e < 10; e++) {
			if (h == e)	continue;
			for (l = 0; l < 10; l++) {
				if (h == l || e == l)	continue;
				for (o = 0; o < 10; o++) {
					if (h == o || e == o || l == o)	continue;
					for (w = 1; w < 10; w++) {
						if (h == w || e == w || l == w || o == w)	continue;
						for (r = 0; r < 10; r++) {
							if (h == r || e == r || l == r || o == r || w == r)	continue;
							for (d = 0; d < 10; d++) {
								if (h == d || e == d || l == d || o == d || w == d || r == d)	continue;
								if (10000 * h + 1000 * e + 120 * l + 1001 * o + 10000 * w + 100 * r + d == n) {
									find = true;
									break;
								}
							}
							if (find)	break;
						}
						if (find)	break;
					}
					if (find)	break;
				}
				if (find)	break;
			}
			if (find)	break;
		}
		if (find)	break;
	}
	if (find) {
		cout << "  " << h << e << l << l << o << '\n';
		cout << "+ " << w << o << r << l << d << '\n';
		cout << "-------\n";
		if (n < 100000)	cout << "  " << n;
		else	cout << ' ' << n;
	}
	else	cout << "No Answer";
}