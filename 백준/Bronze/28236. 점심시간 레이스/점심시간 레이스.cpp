#include <iostream>
using namespace std;

int main() {
	int n, m, k, mn = 100000001, ans;
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		int a, b;
		cin >> a >> b;
		int g = m - b + a;
		if (g < mn)	mn = g, ans = i;
	}
	cout << ans;
}