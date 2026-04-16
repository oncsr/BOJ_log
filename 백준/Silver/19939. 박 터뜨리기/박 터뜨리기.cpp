#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, k;
	cin >> n >> k;
	if (k * (k + 1) / 2 > n)	cout << -1;
	else {
		int a = k * (k + 1) / 2;
		if ((n - a) % k == 0)	cout << k - 1;
		else	cout << k;
	}

}