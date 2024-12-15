#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int k;
	cin >> k;
	cout.precision(5);
	cout << fixed << max(100., min(2000., 25. + k / 100.));

}