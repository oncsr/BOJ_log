#include <iostream>
using namespace std;

int main() {
	int T;
	for (cin >> T; T--;) {
		int a, b, c, s = 0, t, i = 0;
		cin >> a >> b;
		for (t = a + b + 1; i < t; i++) {
			cin >> c;
			if (!i)	s = c;
			else {
				if (a < 1)	s |= c;
				else	s &= c, a--;
			}
		}
		cout << s << '\n';
	}
}