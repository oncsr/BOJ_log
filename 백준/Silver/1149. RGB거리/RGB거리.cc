#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);	cout.tie(0);
	int n;
	cin >> n;
	int d[1001][3]{};
	for (int i = 1; i <= n; i++) {
		cin >> d[i][0] >> d[i][1] >> d[i][2];
		if (i == 1)	continue;
		d[i][0] += min(d[i - 1][1], d[i - 1][2]);
		d[i][1] += min(d[i - 1][0], d[i - 1][2]);
		d[i][2] += min(d[i - 1][0], d[i - 1][1]);
	}
	cout << min(d[n][0], min(d[n][1], d[n][2]));
}