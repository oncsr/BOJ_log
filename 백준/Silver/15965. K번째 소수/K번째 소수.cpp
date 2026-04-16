#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int MX = 7368788;
	int e[7368788]{};
	for (int i = 2; i * i <= MX; i++) {
		if (!e[i]) {
			for (int j = i * i; j <= MX; j += i)	e[j] = 1;
		}
	}
	int c = 0, k;
	cin >> k;
	for (int i = 2;; i++) {
		if (!e[i])	c++;
		if (c == k)	return cout << i, 0;
	}

}