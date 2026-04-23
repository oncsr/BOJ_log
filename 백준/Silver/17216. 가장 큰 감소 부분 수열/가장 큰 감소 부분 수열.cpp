#include <iostream>
using namespace std;

int main() {
	int d[1001]{}, a[1001]{}, n, mx = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[j] < a[i])	d[j] = max(d[j], d[i] + a[j]);
			mx = max(mx, d[j]);
		}
	}
	cout << mx;
}