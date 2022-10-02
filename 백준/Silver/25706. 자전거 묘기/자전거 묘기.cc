#include <iostream>
using namespace std;

int main() {
	int n, d[200001]{}, a[200001]{};
	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> a[i];
	d[n] = 1;
	for (int i = n - 1; i > 0; i--) {
		if (i + 1 + a[i] <= n)	d[i] = d[i + 1 + a[i]] + 1;
		else	d[i] = 1;
	}
	for (int i = 1; i <= n; i++)	cout << d[i] << ' ';
}