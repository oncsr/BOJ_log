#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, a, c[4]{};
	string b, d[4] = { "STRAWBERRY","BANANA","LIME","PLUM" };
	for (cin >> n; n--;) {
		cin >> b >> a;
		for (int i = 0; i < 4; i++)
			if (b == d[i])	c[i] += a;
	}
	for (int i = 0; i < 4; i++) {
		if (c[i] == 5) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}