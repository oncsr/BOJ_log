#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	long long s, n, m, g = 0;
	cin >> s >> n >> m;
	n += m;
	for (; n--;) {
		int a;
		cin >> a;
		if (a)	g++;
		else	g--;
		if (g > s)	s *= 2;
	}
	cout << s;

}