#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, C;
	cin >> N >> C;
	int x = N, y = N;
	for (int a, b; C--;) {
		cin >> a >> b;
		if (a >= x || b >= y)	continue;
		int s1 = a * y, s2 = b * x;
		if (s1 >= s2)	x = a;
		else	y = b;
	}
	cout << x * y;

}