#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, k;
	cin >> n >> k;
	if (n > (long long)k * k) { cout << -1; return 0; }
	
	int G = n - k;
	for (int i = 0; i < (n + k - 1) / k; i++) {
		for (int j = 0; j < k; j++)	if (++G > 0)	cout << G << ' ';
		G -= 2 * k;
	}

}