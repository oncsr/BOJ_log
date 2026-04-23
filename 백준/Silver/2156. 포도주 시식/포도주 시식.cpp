#include <iostream>
using namespace std;
using ll = long long;

int main() {
	int n, a, d[10001][3]{};
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		d[i][0] = max(d[i-1][0], max(d[i - 1][2], d[i - 1][1]));
		d[i][1] = d[i - 1][0] + a;
		if (i > 1)	d[i][2] = d[i - 1][1] + a;
	}
	cout << max(d[n][0], max(d[n][1], d[n][2]));
}