#include <iostream>
using namespace std;

int main() {
	int n, a, d[301][2]{};
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (i==1) { d[i][1] = d[i][0] = a; continue; }
		d[i][0] = d[i - 1][1] + a;
		d[i][1] = max(d[i - 2][0], d[i - 2][1]) + a;
	}
	cout << max(d[n][0], d[n][1]);
}