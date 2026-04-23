#include <iostream>
using namespace std;

int main() {
	int n, k, d[10001]{}, a;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a <= k)	d[a] = 1;
		for (int j = a + 1; j <= k; j++) {
			if (!d[j]) {
				if (d[j - a])	d[j] = d[a] + d[j - a];
			}
			else {
				if (d[j - a]) d[j] = min(d[j], d[a] + d[j - a]);
			}
		}
	}
	cout << (d[k] ? d[k] : -1);
}