#include <bits/stdc++.h>
using namespace std;

int main() {
	int s = 0;
	char ans[4] = { 'N','E','S','W' };
	for (int i = 0; i < 10; i++) {
		int a;
		cin >> a;
		s += a;
	}
	cout << ans[(s + 40) % 4];
}