#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	char t, a;
	cin >> t;
	int l = 0, r = 0;
	while (cin >> a) {
		if (a == t) {
			if (a == '-')	l++;
			else	r++;
		}
		t = a;
	}
	cout << max(l, r);
}