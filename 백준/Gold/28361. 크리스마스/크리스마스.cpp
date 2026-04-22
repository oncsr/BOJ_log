#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, g = 1;
	cin >> n;
	cout << n << '\n';
	if (n % 3 == 2)	cout << g++ << ' ';
	for (int i = 0; i < n / 3; i++) {
		cout << g << ' ' << g + 2 << ' ' << g + 1 << ' ';
		g += 3;
	}
	if (n % 3)	cout << g << ' ';
	cout << 1;
}