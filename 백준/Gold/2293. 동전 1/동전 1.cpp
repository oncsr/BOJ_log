#include <iostream>
using namespace std;

int main() {
	int n, k, d[10001]{}, a;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a <= k)	d[a]++;
		for (int j = a + 1; j <= k; j++)
			d[j] += d[j - a];
	}
	cout << d[k];
}