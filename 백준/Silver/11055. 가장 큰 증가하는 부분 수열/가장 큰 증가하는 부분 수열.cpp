#include <iostream>
using namespace std;

int main() {
	int n, d[1001]{}, a[1001]{}, m = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> a[i];
	for (int i = 1; i <= n; i++) {
		if (!d[i])	d[i] = a[i];
		m = max(d[i], m);
		for (int j = i + 1; j <= n; j++)
			if (a[j] > a[i]) {
				d[j] = max(d[j], d[i] + a[j]);
				m = max(d[j], m);
			}
	}
	cout << m;
}