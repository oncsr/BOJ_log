#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);	cout.tie(0);
	int n, mx;
	int d[100001]{};
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
		if (i == 1) {
			mx = d[i];
			continue;
		}
		d[i] = (d[i - 1] < 0 ? d[i] : d[i - 1] + d[i]);
		mx = max(mx, d[i]);
	}
	cout << mx;
}