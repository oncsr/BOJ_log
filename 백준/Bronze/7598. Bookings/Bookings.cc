#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s;
	int n;
	for (cin >> s >> n; s != "#"; cin >> s >> n) {
		char a;
		int b;
		for (cin >> a >> b; a != 'X'; cin >> a >> b) {
			if (a == 'B') {
				if (n + b > 68)	continue;
				n += b;
			}
			else {
				if (b > n)	continue;
				n -= b;
			}
		}
		cout << s << ' ' << n << '\n';
	}

}