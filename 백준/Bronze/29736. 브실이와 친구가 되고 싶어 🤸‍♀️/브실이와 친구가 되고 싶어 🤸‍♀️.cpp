#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int a, b, k, x, s = 0;
	cin >> a >> b >> k >> x;
	for (int i = k - x; i <= k + x; i++) {
		if (a <= i && i <= b)	s++;
	}
	if (s)	cout << s;
	else	cout << "IMPOSSIBLE";
}