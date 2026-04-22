#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int b = 0, r = 0, n;
	char t = ' ';
	for (cin >> n; n--;) {
		char a;
		cin >> a;
		if (a != t) {
			if (a == 'B')	b++;
			else	r++;
		}
		t = a;
	}
	cout << min(b, r) + 1;
}