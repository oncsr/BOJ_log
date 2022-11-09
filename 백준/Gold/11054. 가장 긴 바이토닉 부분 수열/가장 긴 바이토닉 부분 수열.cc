#include <iostream>
using namespace std;

int main() {
	int d1[1001]{}, a[1001]{}, d2[1001]{}, n;
	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> a[i];
	for (int i = 1; i <= n; i++)	d1[i] = d2[i] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (a[j] > a[i])	d1[j] = max(d1[j], d1[i] + 1);
	for (int i = n; i >= 1; i--)
		for (int j = i - 1; j >= 1; j--)
			if (a[j] > a[i])	d2[j] = max(d2[j], d2[i] + 1);
	int mx = 0;
	for (int k = 1; k <= n; k++) {
		mx = max(mx, d1[k] + d2[k] - 1);
	}
	cout << mx;
}