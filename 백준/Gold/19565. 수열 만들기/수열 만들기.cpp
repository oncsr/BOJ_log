#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	cout << n * n + 1 << '\n';
	for (int i = 1; i <= n; i++)	cout << i << ' ' << i << ' ';
	for (int i = n; i > 1; i--) {
		for (int j = 1; j < i - 1; j++)	cout << j << ' ' << i << ' ';
		cout << i - 1 << ' ';
	}
}