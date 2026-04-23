#include <iostream>
using namespace std;

int main() {
	int t;
	for (cin >> t; t--;) {
		int n, k, d[10001]{}, a;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a;
			d[a]++;
			for (int j = a + 1; j <= 10000; j++)
				d[j] += d[j - a];
		}
		cin >> k;
		cout << d[k] << '\n';
	}
}