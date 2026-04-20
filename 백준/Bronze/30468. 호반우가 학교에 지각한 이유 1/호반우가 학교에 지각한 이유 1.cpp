#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	cout << max(0, 4 * e - (a + b + c + d));

}