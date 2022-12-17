#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int e[100000001]{}, n;
	for (int i = 2; i * i <= 100000000; i++)
		if (!e[i])
			for (int j = i * 2; j <= 100000000; j += i)
				e[j] = 1;
	while (cin >> n) {
		int S = n, a = 0, b = 0, c = 0, d = 0;
		for (int i = S - 6; i >= 2; i--)
			if (!e[i]) {
				a = i;
				break;
			}
		S -= a;
		for (int i = S - 4; i >= 2; i--)
			if (!e[i]) {
				b = i;
				break;
			}
		S -= b;
		for (int i = S - 2; i >= 2; i--)
			if (!e[i]) {
				c = i;
				break;
			}
		S -= c;
		for (int i = S; i >= 2; i--)
			if (!e[i]) {
				d = i;
				break;
			}
		S -= d;
		if (!a || !b || !c || !d)	cout << "Impossible.";
		else	cout << d << ' ' << c << ' ' << b << ' ' << a;
		cout << '\n';
	}
}